/*
Created by flo071
*/
#define F_CPU 10000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "include/LCD/lcd.c"
#include "include/KEYPAD/keypad.c"

int value=0;

int main(void){
	lcd_init();
	keypad_init();
    while(1){
    	keypad_display_test();
    }
}

int keypad_display_test(){
	keypad();
	value = keypad();
	switch(value){
		case  0: lcd_string("   No key pressed.  ");
		case  1: lcd_string(" 1 has been pressed.");
		case  2: lcd_string(" 2 has been pressed.");
		case  3: lcd_string(" 3 has been pressed.");
		case  4: lcd_string(" 4 has been pressed.");
		case  5: lcd_string(" 5 has been pressed.");
		case  6: lcd_string(" 6 has been pressed.");
		case  7: lcd_string(" 7 has been pressed.");
		case  8: lcd_string(" 8 has been pressed.");
		case  9: lcd_string(" 9 has been pressed.");
		case 10: lcd_string(" * has been pressed.");
		case 11: lcd_string(" 0 has been pressed.");
		case 12: lcd_string(" # has been pressed.");
		case 13: lcd_string(" A has been pressed.");
		case 14: lcd_string(" B has been pressed.");
		case 15: lcd_string(" C has been pressed.");
		case 16: lcd_string(" D has been pressed.");
	}
}
