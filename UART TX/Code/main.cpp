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
	DDRD &= ~((1<<2)|(1<<3));//set PD2,PD3 as input
	PORTD |= (1<<2)|(1<<3);//activate pull ups in PD2,PD3
	uart uart1 = uart(_8MHZ,9600);//using F_CPU 8MHZ and baud rate 9600
	
    while (1) 
    {
		if(bit_is_clear(PIND,2)){//if PIND in PD2 clear
			uart1.setTransmitter('a');//send character 'a'
			_delay_ms(500);//pause 500 milliseconds
		}
		if(bit_is_clear(PIND,3)){//if PIND in PD3 clear
			uart1.setString(" hello ");//send the string "hello"
			_delay_ms(500);//pause 500 milliseconds		
		}
    }
}

