/*
Created by flo071
*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "include/signals.c"
#include "include/LCD/lcd.c"
#include "include/keyboard/keyboard.c"

int main(void){
	start();
    while(1){
    	menu();
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
	//LCD Init/Setup
	lcd_init();
	keyboardInit();
	lcd_setcursor(1,0);
	lcd_string("Function Generator");
	_delay_ms(4000);
	lcd_clear();
}

int menu(void){
	lcd_setcursor(0,0);
	lcd_string("Menu");
	_delay_ms(4000); 	//Timeout to show this
	lcd_clear();
	//Show output options and make it selectable
	while(1){
		//column 1
		lcd_setcursor(0,0);
		lcd_string("1: 1k");
		lcd_setcursor(0,1);
		lcd_string("2: 2k");
		lcd_setcursor(0,2);
		lcd_string("3: 5k");
		lcd_setcursor(0,3);
		lcd_string("4:10k");
		//column 2
		lcd_setcursor(6,0);
		lcd_string("5: 50k");
		lcd_setcursor(6,1);
		lcd_string("6:100k");
		lcd_setcursor(6,2);
		lcd_string("7:500k");
		lcd_setcursor(6,3);
		lcd_string("8:  1M");
		//column 3
		lcd_setcursor(13,0);
		lcd_string("9:10M");
		lcd_setcursor(13,1);
		lcd_string("*:20M");
		lcd_setcursor(13,2);
		lcd_string("0:36M");
		lcd_setcursor(13,3);
		_delay_ms(1000);
		keyboard();
		if(keyboard()>0){
			char out_d[30];
			itoa(keyboard(), out_d, 30);
			lcd_string(out_d);
			if(keyboard()==1){
				k1_sig();
			} else if(keyboard()==2){
				k2_sig();
			} else if(keyboard()==3){
				k5_sig();
			} else if(keyboard()==4){
				k10_sig();
			} else if(keyboard()==5){
				k50_sig();
			} else if(keyboard()==6){
				k100_sig();
			} else if(keyboard()==7){
				k500_sig();
			} else if(keyboard()==8){
				M1_sig();
			} else if(keyboard()==9){
				M10_sig();
			} else if(keyboard()==10){
				M20_sig();
			} else if(keyboard()==11){
				M36_sig();
			} else if(keyboard()==12){
				reset_sig();
			} 
		}
	}
	return 0;
}


