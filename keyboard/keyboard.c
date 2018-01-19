#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "keyboard.h"

int keyboardInit(){
	DDRD  = 0b01110000;
	PORTD = 0b00001111;
}

int keyboard(out){

	while(1){
		out = 0;

		PORTD=COLUMN1;	//column 1
		if((PIND | ROW1)==ROW1){
			out=out+1;		//key 1
		}

		if((PIND | ROW2)==ROW2){
			out=out+4;		//key 4
		}

		if((PIND | ROW3)==ROW3){
			out=out+7;		//key 7
		}

		if((PIND | ROW4)==ROW4){
			out=out+10;		//key *
		}

		PORTD=COLUMN2;	//column 2
		if((PIND | ROW1)==ROW1){
			out=out+2;		//key 2
		}

		if((PIND | ROW2)==ROW2){
			out=out+5;		//key 5
		}

		if((PIND | ROW3)==ROW3){
			out=out+8;		//key 8
		}

		if((PIND | ROW4)==ROW4){
			out=out+0;		//key 0
		}

		PORTD=COLUMN3;	//column 3
		if((PIND | ROW1)==ROW1){
			out=out+3;		//key 3
		}

		if((PIND | ROW2)==ROW2){
			out=out+6;		//key 6
		}

		if((PIND | ROW3)==ROW3){
			out=out+9;		//key 9
		}
	
		if((PIND | ROW4)==ROW4){
			out=out+12;		//key #
		}
	}
	return out;
}
