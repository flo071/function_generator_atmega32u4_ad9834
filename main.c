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
	//test_keypad();
}

int init(void){
	//Disable JTAG, Display is connected here
	MCUCR |=(1<<JTD);
	MCUCR |=(1<<JTD);
	//Set DDRD as input
	init_test_keys();	//init test keys
	//keypad_init();	//init keypad
	//Start the initialisation of the actual code
	lcd_init();		//found in lcd.c
	_delay_ms(500);
	menu_layout();	//found in menu.c
	print_unit();	//found in menu.c
}

int init_test_keys(void){
	DDRD = 0x00;	//Test keys
	PORTD = 0xFF;	//Test keys
}

/*int test_keypad(void){
	while(1){
		whatkey();		
	}
}*/