/*
Created by flo071
*/
#define F_CPU 10000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "include/LCD/lcd.c"

int A=0, B=0, C=0, D=0, SET=1;

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
	lcd_string("Wave:            [A]");
	lcd_setcursor(0,1);
	lcd_string("Frequency:       [B]");
	lcd_setcursor(0,2);
	lcd_string("Amplitude:       [C]");
	lcd_setcursor(0,3);
	lcd_string("Offset:          [D]");
	if((A|B|C|D)&SET==1){
		lcd_setcursor(0,0);
		lcd_string("sine");
		lcd_setcursor(0,1);
		lcd_string("1kHz");
		lcd_setcursor(0,2);
		lcd_string("5Vpp");
		lcd_setcursor(0,3);
		lcd_string("0Vdc");
	}
}
