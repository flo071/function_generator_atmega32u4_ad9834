#include "signals.h"

//sin
int sk1_sig(void){
	SPDR = sk1_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = sk1_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int sk2_sig(void){
	SPDR = sk2_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = sk2_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int sk5_sig(void){
	SPDR = sk5_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = sk5_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int sk10_sig(void){
	SPDR = sk10_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = sk10_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int sk50_sig(void){
	SPDR = sk50_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = sk50_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int sk100_sig(void){
	SPDR = sk100_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = sk100_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int sk500_sig(void){
	SPDR = sk500_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = sk500_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int sM1_sig(void){
	SPDR = sM1_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = sM1_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int sM10_sig(void){
	SPDR = sM10_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = sM10_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int sM20_sig(void){
	SPDR = sM20_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = sM20_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int sM36_sig(void){
	SPDR = sM36_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = sM36_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}

//tri
int tk1_sig(void){
	SPDR = tk1_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = tk1_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int tk2_sig(void){
	SPDR = tk2_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = tk2_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int tk5_sig(void){
	SPDR = tk5_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = tk5_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int tk10_sig(void){
	SPDR = tk10_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = tk10_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int tk50_sig(void){
	SPDR = tk50_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = tk50_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int tk100_sig(void){
	SPDR = tk100_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = tk100_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int tk500_sig(void){
	SPDR = tk500_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = tk500_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int tM1_sig(void){
	SPDR = tM1_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = tM1_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int tM10_sig(void){
	SPDR = tM10_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = tM10_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int tM20_sig(void){
	SPDR = tM20_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = tM20_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}
int tM36_sig(void){
	SPDR = tM36_1;		//first 8 bit
	PORTB &= ~(1<<PB4); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = tM36_2;		//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	signalselect();
	return 0;
}

//reset
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
	signalselect();
	return 0;
}