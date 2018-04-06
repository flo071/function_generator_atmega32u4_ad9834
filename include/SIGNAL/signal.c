/*
Created by flo071

SPI needs to be configured to send MSB first
Only using Frequency 0 and Phase 0 Register here

Frequency Registers need 28 Bits + 4 Control Bits
Phase Registers need 12 Bits + 4 Control Bits

1 MHz for testing:
01   000000
   11100111
01   010011
   01100000
*/
#define F_CPU 10000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "signal.h"

#define str1 0b01000000
#define str2 0b11100111
#define str3 0b01010011
#define str4 0b01100000

int SPI_setup(void){
	//Setup Pins for SPI
	DDRB  |=  (1<<PB0); //SlaveSelect
	DDRB  |=  (1<<PB1); //CLK
	DDRB  |=  (1<<PB2); //MOSI
	DDRB  &= ~(1<<PB3); //MISO
	DDRB  |=  (1<<PB4); //SS Dummy
	DDRB  |=  (1<<PB7); //SS for manual bit selection, like 16bit here
	PORTB |=  (1<<PB7); //SS active low set high
	//Setup SPI
	//SPI init
	SPCR &=~ (1<<DORD); //Data order MSB first
	SPCR |=  (1<<MSTR); //Master mode
	SPCR &= ~(1<<CPOL); //sclk rising edge
	SPCR &= ~(1<<CPHA); //sclk phase 
	SPCR |=  (1<<SPR1); //sclk prescaler /64
	SPCR |=  (1<<SPR0); //sclk prescaler /64
	SPSR |=  (1<<SPI2X);//sclk prescaler /64
}

int control_set(void){
	SPDR = CTRLw1;
	PORTB &= ~(1<<PB7); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = CTRLw2;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	PORTB |= (1<<PB7); 	//SlaveSelect set high
}

int frequency_set(void){
	SPDR = FRQ0 | str1;
	PORTB &= ~(1<<PB7); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = FRQ0 | str2;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = FRQ0 | str3;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = FRQ0 | str4;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);	
	PORTB |= (1<<PB7); 	//SlaveSelect set high
}

int phase_set(void){
	SPDR = PHS0;
	PORTB &= ~(1<<PB7); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = 0b00000000;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	PORTB |= (1<<PB7); 	//SlaveSelect set high
}

int out_sin(void){
	SPDR = OUTsin1;
	PORTB &= ~(1<<PB7); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = OUTsin2;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	PORTB |= (1<<PB7); 	//SlaveSelect set high
}

int out_tri(void){
	SPDR = OUTtri1;
	PORTB &= ~(1<<PB7); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = OUTtri2;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	PORTB |= (1<<PB7); 	//SlaveSelect set high
}

int out_rect(void){
	SPDR = OUTrect1;
	PORTB &= ~(1<<PB7); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = OUTrect2;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	PORTB |= (1<<PB7); 	//SlaveSelect set high
}

int signal_sin(void){
	control_set();
	frequency_set();
	phase_set();
	out_sin();
}

int signal_tri(void){
	control_set();
	frequency_set();
	phase_set();
	out_tri();
}

int signal_rect(void){
	control_set();
	frequency_set();
	phase_set();
	out_rect();
}