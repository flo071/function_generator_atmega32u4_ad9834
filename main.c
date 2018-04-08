/*
Created by flo071
*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "include/LCD/lcd.c"
#include "include/KEYPAD/keypad.c"
#include "include/SIGNAL/signal.c"

int value=0;

int setup(void){
	//Disable JTAG
    MCUCR =  (1<<JTD);
    MCUCR =  (1<<JTD);
}

int main(void){
	setup();
	SPI_setup();
	LCD_setup();
	KEYPAD_setup();
    while(1){
    	keypad_display_test();
    }
}

int keypad_display_test(){
	keypad();
	value = keypad();
	switch(value){
		case  0: lcd_string(" 0 has been pressed.");
		case  1: lcd_string("Sin output"); signal_sin();
		case  2: lcd_string("Tri output"); signal_tri();
		case  3: lcd_string("Rect output"); signal_rect();
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
