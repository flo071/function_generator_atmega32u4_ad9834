/*
Created by flo071
*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

int x=0;

int main(void){
	start();
    while(1){
	if(x==0){
    		M1_sig();
	} else{
		//do nothing
	}
    }
}

int start(void){
	//Disable JTAG
	MCUCR =  (1<<JTD);
    	MCUCR =  (1<<JTD);
    	//Setup Pins for SPI
    	DDRB |=  (1<<PB0);  //FSYNC
	DDRB |=  (1<<PB1);  //SCLK
	DDRB |=  (1<<PB2);  //MOSI
	DDRB &= ~(1<<PB3);  //MISO
	DDRB |=  (1<<PB4);  //FSELECT
	DDRB |=  (1<<PB5);  //PSELECT
	DDRB &= ~(1<<PB6);  //RESET
	//Setup SPI
	//SPI init
	SPCR &= ~(1<<DORD); //Data order MSB first
	SPCR |=  (1<<MSTR); //Master mode
	SPCR &= ~(1<<CPOL); //sclk rising edge
	SPCR &= ~(1<<CPHA); //sclk phase 
	SPCR |=  (1<<SPR1); //sclk prescaler /64
	SPCR |=  (1<<SPR0); //sclk prescaler /64
	SPSR |=  (1<<SPI2X);//sclk prescaler /64
}

int M1_sig(){
	x=1;
	SPDR = 0b00000011;	//first 8 bit
	PORTB &= ~(1<<PB4); 	//SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the first 8bit to be send
	SPDR = 0b10011101;	//second 8 bit
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 8bit to be send
	SPDR = 0b00110110;	//third 8 bit
	PORTB &= ~(1<<PB4); 	//SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = 0b0000;		//last 4 bit
	PORTB &= ~(1<<PB4); 	//SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the last 4 bit to be send
	PORTB |= (1<<PB4); 	//SlaveSelect set high, to start ad9834 output
	return x;
}
