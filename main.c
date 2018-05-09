/*
Created by flo071
*/
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "main.h"
#include "include/lcd/lcd.c"
#include "include/menu/menu.c"
#include "include/menu/settings.c"
#include "include/keypad/keypad.c"

int main(void) {
	init();
	menu_nav();		//found in menu.c
}

int init(void){
	//Disable JTAG, Display is connected here
	MCUCR |=(1<<JTD);
	MCUCR |=(1<<JTD);
	keypad_init();	//init keypad
	//Start the initialisation of the actual code
	lcd_init();		//found in lcd.c
	_delay_ms(1);
	menu_layout();	//found in menu.c
}

