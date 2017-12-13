/***************************************

SPI for MAX512(DAC) with the Atmega32u4
creator:    dominik gansch
first edit: 24.10.2017
last edit:  22.11.2017

****************************************/
#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int spi(void){

	//PORT init
	DDRB |=  (1<<PB0);//SS (only 8bit)
	DDRB |=  (1<<PB1);//CLK
	DDRB |=  (1<<PB2);//MOSI
	DDRB &= ~(1<<PB3);//MISO
	DDRB |=  (1<<PB4);//SS for manual bit selection, like 16bit here
	DDRD |= (1<<PD7); //indicator led fot testing purposes

	PORTB |= (1<<PB4); //SS active low set high

	//SPI init
	SPCR &= ~(1<<DORD); //Data order MSB first
	SPCR |=  (1<<MSTR); //Master mode
	SPCR &=  ~(1<<CPOL); //sclk rising edge
	SPCR &=  ~(1<<CPHA); //sclk phase 

	SPCR |=  (1<<SPR1); //sclk prescaler /64
	SPCR |=  (1<<SPR0); //sclk prescaler /64

	SPSR |=  (1<<SPI2X);//sclk prescaler /64

	//interrupt and SPIF flag enable
	//SPCR |= (1<<SPIE); //SPI interrupt enable
	//sei();

	while(1){

		SPDR = 0b00110001;	//DAC settings; Set LOUT to low, only OUTA active, only load DAC A data register
		PORTB &= ~(1<<PB4); //SlaveSelect set low
		_delay_ms(1);	//wait for SS to be set to low
		SPCR |=  (1<<SPE); //SPI enable (start data tranfer)
		_delay_ms(10);	//wait for the first 8bit to be send

		//if(SPIF == 1)PORTB |= (1<<PD7); _delay_ms(50); //test if SPIF works

		SPDR = 0b10101000;	//DAC data for the lovel of the output voltage
		SPCR |=  (1<<SPE); //SPI enable (start data tranfer)
		_delay_ms(10);	//wait for the last 8bit to be send
		PORTB |= (1<<PB4); //SlaveSelect set high
	}
}