/*
Created by flo071
*/
#define F_CPU 10000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "include/LCD/lcd.c"

int main(void){
	lcd_init();
    while(1){

    }
}

int lcd_init(void){
	//LCD Init/Setup
	lcd_init();
	keyboardInit();
	lcd_setcursor(1,0);
	lcd_string("Function Generator");
	_delay_ms(4000);
	lcd_clear();
}

int menu(){
	lcd_setcursor(0,0);
	lcd_string("Wave             [1]");
	lcd_setcursor(0,0);
	lcd_string("Frequency        [2]");
	lcd_setcursor(0,0);
	lcd_string("Amplitude        [3]");
	lcd_setcursor(0,0);
	lcd_string("Offset           [4]");
}
