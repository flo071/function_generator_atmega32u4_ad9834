  #include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "keyboard.h"


int keyboard(value){
	DDRD=0b01110000;
	PORTD=0b00001111;

	while(1){
		key0=0;
		key1=0;
		value=0;

		//1
		PORTD=0b01011111;
			if((PIND | ZEILE2)==ZEILE2){
				value=key0+4;	//key 5
			}
		//2
		PORTD=0b01101111;
			if((PIND | ZEILE2)==ZEILE2){
				value=key0+6;	//key 6
			}
		//3
		PORTD=0b00111111;
			if((PIND | ZEILE2)==ZEILE2){
				value=key0+5;	//key 4
			}
		//4
		PORTD=0b01011111;
			if((PIND | ZEILE1)==ZEILE1){
				value=key0+2;	//key 2
			}
		//5
		PORTD=0b01101111;
			if((PIND | ZEILE1)==ZEILE1){
				value=key0+1;	//key 3
			}
		//6
		PORTD=0b00111111;
			if((PIND | ZEILE1)==ZEILE1){
				value=key0+3;	//key 1
			}
		//7
		PORTD=0b01011111;
			if((PIND | ZEILE4)==ZEILE4){
				value=key1+2;	//key 0
			}
		//8
		PORTD=0b01101111;
			if((PIND | ZEILE4)==ZEILE4){
				value=key1+4;	//key #
			}
		//9
		PORTD=0b00111111;
			if((PIND | ZEILE4)==ZEILE4){
				value=key1+3;	//key *
			}
		//*
		PORTD=0b01011111;
			if((PIND | ZEILE3)==ZEILE3){
				value=key0+7;	//key 8
			}
		//0
		PORTD=0b01101111;
			if((PIND | ZEILE3)==ZEILE3){
				value=key1+1;	//key 9
			}
		//#
		PORTD=0b00111111;
			if((PIND | ZEILE3)==ZEILE3){
				value=key0+8;	//key 7
			}
	}
	return value;
}
