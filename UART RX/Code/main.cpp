/*
 * UART(RX) ATMEGA8A (C++).cpp
 *
 * Created: 25/12/2022 10.42.07
 * Author : fisikamodern
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "uart.hpp"
#define F_CPU 8000000

int main(void)
{
	DDRD |= (1<<2)|(1<<3);
	uart uart1 = uart(_8MHZ,9600);
	
    while (1) 
    {
		switch(uart1.getReceive()){
			case 'a': PORTD = (1<<2); break;
			case 'b': PORTD = (1<<3); break;	
		}
    }
}

