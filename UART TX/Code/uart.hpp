/*
 * uart.h
 *
 * Created: 14/12/2022 11.18.24
 *  Author: fisikamodern
 */ 


#ifndef UART_H_
#define UART_H_

typedef enum{
	_1MHZ=1000000,
	_2MHZ=2000000,
	_3MHZ=3000000,
	_4MHZ=4000000,
	_5MHZ=5000000,
	_6MHZ=6000000,
	_7MHZ=7000000,
	_8MHZ=8000000,
	_9MHZ=9000000,
	_10MHZ=10000000,
	_11MHZ=11000000,
	_12MHZ=12000000,
	_13MHZ=13000000,
	_14MHZ=14000000,
	_15MHZ=15000000,
	_16MHZ=16000000
}Fcpu;

class uart{
	private:
		Fcpu fcpu;
		unsigned long BaudRate;
		unsigned long ValueUBRR;
		void init(Fcpu fcpu,unsigned long BaudRate);
	public:
		uart(Fcpu fcpu,unsigned long BaudRate);
		uint8_t getReceive();
		void setTransmitter(uint8_t data);
		void setString(const char *str);
		
};



#endif /* UART_H_ */