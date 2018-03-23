/*
Created by flo071
*/
#define F_CPU 10000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "include/LCD/lcd.c"
#include "include/KEYPAD/keypad.c"

int A=0, B=0, C=0, D=0, SET=1;

int main(void){
	lcd_init();
	keypad_init();
    while(1){
    	keypad_display_test();
    }
}

int keypad_display_test(){
	keypad();
	if(keypad>=0){
		lcd_string("You pressed a key");
	}
	else{
		lcd_string("No key pressed");
	}
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
