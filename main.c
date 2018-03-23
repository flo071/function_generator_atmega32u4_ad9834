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
	keypad_init();
    while(1){
    	keypad();
    }
}
