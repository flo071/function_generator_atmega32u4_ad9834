#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "keyboard.h"

#define ZEILE1 0b11111110
#define ZEILE2 0b11111101
#define ZEILE3 0b11111011
#define ZEILE4 0b11110111
unsigned int out;

int keyboard(out){
	DDRD=0b01110000;
	PORTD=0b00001111;

	while(1){
		out = 0;

		PORTD=0b00111111;	//row 1
		if((PIND | ZEILE1)==ZEILE1){
			out=out+3;		//key 3
		}

		if((PIND | ZEILE2)==ZEILE2){
			out=out+4;		//key 4
		}

		if((PIND | ZEILE3)==ZEILE3){
			out=out+7;		//key 7
		}

		if((PIND | ZEILE4)==ZEILE4){
			out=out+10;		//key *
		}

		PORTD=0b01011111;	//row 2
		if((PIND | ZEILE1)==ZEILE1){
			out=out-2;		//key 1
		}

		if((PIND | ZEILE2)==ZEILE2){
			out=out+5;		//key 5
		}

		if((PIND | ZEILE3)==ZEILE3){
			out=out+8;		//key 8
		}

		if((PIND | ZEILE4)==ZEILE4){
			out=out+11;		//key 0
		}

		PORTD=0b01101111;	//row 3
		if((PIND | ZEILE1)==ZEILE1){
			out=out-1;		//key 2
		}

		if((PIND | ZEILE2)==ZEILE2){
			out=out+6;		//key 6
		}

		if((PIND | ZEILE3)==ZEILE3){
			out=out+9;		//key 9
		}
	
		if((PIND | ZEILE4)==ZEILE4){
			out=out+12;		//key #
		}
	}
	return value;
}
