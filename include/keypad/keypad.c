/*
Created by flo071
*/
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "keypad.h"



int keypad_init() {
	DDRD  = keypadPORT;
	PORTD = keypadKEYS;
}

int keypad(void) {
	
	while (1) {
		out=0;
		PORTD = COLUMN1;	//column 1
		if ((PIND | ROW1) == ROW1) {
			out = out + 1;		//key 1
		}
		if ((PIND | ROW2) == ROW2) {
			out = out + 11;		//key 0
		}
		if ((PIND | ROW3) == ROW3) {
			out = out + 12;		//key #
		}
		if ((PIND | ROW4) == ROW4) {
			out = out + 16;		//key D
		}

		PORTD = COLUMN2;	//column 2
		if ((PIND | ROW1) == ROW1) {
			out = out + 10;		//key *
		}
		if ((PIND | ROW2) == ROW2) {
			out = out + 8;		//key 8
		}
		if ((PIND | ROW3) == ROW3) {
			out = out + 9;		//key 9
		}
		if ((PIND | ROW4) == ROW4) {
			out = out + 15;		//key C
		}

		PORTD = COLUMN3;	//column 3
		if ((PIND | ROW1) == ROW1) {
			out = out + 7;		//key 7
		}
		if ((PIND | ROW2) == ROW2) {
			out = out + 5;		//key 5
		}
		if ((PIND | ROW3) == ROW3) {
			out = out + 6;		//key 6
		}
		if ((PIND | ROW4) == ROW4) {
			out = out + 14;		//key B
		}

		PORTD = COLUMN4; //column 4
		if ((PIND | ROW1) == ROW1) {
			out = out + 4;		//key 4
		}
		if ((PIND | ROW2) == ROW2) {
			out = out + 2;		//key 2
		}
		if ((PIND | ROW3) == ROW3) {
			out = out + 3;		//key 3
		}
		if ((PIND | ROW4) == ROW4) {
			out = out + 13;		//key A
		}
		return out;
	}
	
}

int whatkey(void){
	keypad();
	switch(out){
		case 1:  lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("1"); break;
		case 2:  lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("2"); break;
		case 3:  lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("3"); break;
		case 4:  lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("4"); break;
		case 5:  lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("5"); break;
		case 6:  lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("6"); break;
		case 7:  lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("7"); break;
		case 8:  lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("8"); break;
		case 9:  lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("9"); break;
		case 10: lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("*"); break;
		case 11: lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("0"); break;
		case 12: lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("#"); break;
		case 13: lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("A"); break;
		case 14: lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("B"); break;
		case 15: lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("C"); break;
		case 16: lcd_clr_line(1); lcd_setcursor(0,1); lcd_string("D"); break;
	}
}
