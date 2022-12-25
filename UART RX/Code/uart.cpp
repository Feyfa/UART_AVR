/*
 * uart.cpp
 *
 * Created: 14/12/2022 11.18.36
 *  Author: fisikamodern
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "uart.hpp"
// ( (fcpu / (BaudRate * 16)) - 1 )

//private method
void uart::init(Fcpu fcpu,unsigned long BaudRate){
	uart::ValueUBRR = ( (fcpu / (BaudRate * 16)) - 1 );
	UCSRB |= (1 << RXEN) | (1 << TXEN); /* Enable USART transmitter and receiver */
	UCSRC |= (1 << URSEL)| (1 << UCSZ0) | (1 << UCSZ1);	/* Write USCRC for 8 bit data and 1 stop bit */
	UBRRL = uart::ValueUBRR; /* Load UBRRL with lower 8 bit of prescale value */
	UBRRH = (uart::ValueUBRR >> 8); /* Load UBRRH with upper 8 bit of prescale value */
}

//public method
uart::uart(Fcpu fcpu,unsigned long BaudRate){
	uart::fcpu = fcpu;
	uart::BaudRate = BaudRate;
	uart::init(uart::fcpu,uart::BaudRate);
}
uint8_t uart::getReceive(){
	while (!(UCSRA & (1 << RXC))); /* Wait until new data receive */
	return(UDR); /* Get and return received data */
}
void uart::setTransmitter(uint8_t data){
	UDR = data; /* Write data to be transmitting in UDR */
	while (!(UCSRA & (1<<UDRE))); /* Wait until data transmit and buffer get empty */
}
void uart::setString(const char *str){
	int i=0;
	while (str[i]!=0)
	{
		uart::setTransmitter(str[i]); /* Send each char of string till the NULL */
		i++;
	}
}
