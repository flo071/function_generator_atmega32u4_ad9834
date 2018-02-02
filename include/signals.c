#include "signals.h"

int k1_sig(void){
	SPDR = k1_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = k1_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	menu();
	return 0;
}
int k2_sig(void){
	SPDR = k2_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = k2_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	menu();
	return 0;
}
int k5_sig(void){
	SPDR = k5_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = k5_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	menu();
	return 0;
}
int k10_sig(void){
	SPDR = k10_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = k10_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	menu();
	return 0;
}
int k50_sig(void){
	SPDR = k50_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = k50_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	menu();
	return 0;
}
int k100_sig(void){
	SPDR = k100_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = k100_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	menu();
	return 0;
}
int k500_sig(void){
	SPDR = k500_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = k500_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	menu();
	return 0;
}
int M1_sig(void){
	SPDR = M1_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = M1_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	menu();
	return 0;
}
int M10_sig(void){
	SPDR = M10_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = M10_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	menu();
	return 0;
}
int M20_sig(void){
	SPDR = M20_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = M20_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	menu();
	return 0;
}
int M36_sig(void){
	SPDR = M36_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = M36_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	menu();
	return 0;
}
int reset_sig(void){
	SPDR = RESET;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = RESET;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	menu();
	return 0;
}