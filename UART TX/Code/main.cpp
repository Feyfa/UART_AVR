/*
 * UART(TX) ATMEGA8A (C++).cpp
 *
 * Created: 25/12/2022 10.20.14
 * Author : fisikamodern
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "uart.hpp"
#define  F_CPU 8000000

int main(void)
{
	DDRD &= ~((1<<2)|(1<<3));
	PORTD |= (1<<2)|(1<<3);
	uart uart1 = uart(_8MHZ,9600);
	
    while (1) 
    {
		if(bit_is_clear(PIND,2)){
			uart1.setTransmitter('a');
			_delay_ms(500);	
		}
		if(bit_is_clear(PIND,3)){
			uart1.setString(" hello ");
			_delay_ms(500);		
		}
    }
}

