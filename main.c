#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd/LCD.c"
//#include "keyboard/keyboard.c"

void SPI_MasterInit(void){
	DDRB = (1<<PB2)|(1<<PB1);
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
void SPI_MasterTransmit(char cData){
	SPDR = cData;
	while(!(SPSR & (1<<SPIF)));
}
int main(void){
	PORTB=0xFF;
    lcd_init();
    for(;;){
    	
    }
	return 0;
}