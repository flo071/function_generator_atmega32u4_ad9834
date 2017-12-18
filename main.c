#define F_CPU 2000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LCD/lcd.c"

int main(void){
	start();

    while(1){
    	menu();
    	signals();
    }
}

int start(void){
	MCUCR =  (1<<JTD);
    MCUCR =  (1<<JTD);
    //Setup Pins for SPI and indicator LED
    DDRB |=  (1<<PB0);  //FSYNC
	DDRB |=  (1<<PB1);  //SCLK
	DDRB |=  (1<<PB2);  //MOSI
	DDRB &= ~(1<<PB3);  //MISO
	DDRB |=  (1<<PB4);  //FSELECT
	DDRB |=  (1<<PB5);  //PSELECT
	DDRB &= ~(1<<PB6);  //RESET
	DDRB |=  (1<<PB7);  //Indicator LED
	//Setup SPI
	//SPI init
	SPCR &= ~(1<<DORD); //Data order MSB first
	SPCR |=  (1<<MSTR); //Master mode
	SPCR &= ~(1<<CPOL); //sclk rising edge
	SPCR &= ~(1<<CPHA); //sclk phase 
	SPCR |=  (1<<SPR1); //sclk prescaler /64
	SPCR |=  (1<<SPR0); //sclk prescaler /64
	SPSR |=  (1<<SPI2X);//sclk prescaler /64
	lcd_init();
	lcd_setcursor(1,0);
	lcd_string("Function Generator");
	_delay_ms(4000);
	lcd_clear();
}

int menu(void){
	lcd_setcursor(0,0);
	lcd_string("Menu");
	PORTB = (1<<PB7);
	//TODO import and rewrite keyboard functions and build a menu for navigating with it
}

int signals(void){
	//TODO write code for AD9834 to send out the right signals (SPI)
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

