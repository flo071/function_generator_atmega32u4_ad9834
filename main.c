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
	MCUCR = (1<<JTD);
    MCUCR = (1<<JTD);
	lcd_init();
	lcd_setcursor(1,0);
	lcd_string("Function Generator");
	_delay_ms(4000);
	lcd_clear();
}

int menu(void){
	lcd_setcursor(0,0);
	lcd_string("Menu");
	//TODO import and rewrite keyboard functions and build a menu for navigating with it
}

int signals(void){
	//TODO write code for AD9834 to send out the right signals (SPI)
}

