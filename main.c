#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd/LCD.c"

int main(void){
    lcd_init();
    PORTB=0xFF;
    for(;;){
    	void spi_init_master (void){
    		DDRB=(1<<1)|(1<<2);								//MOSI & SCK as output
    		SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPIE);	//Enable SPI
    		sei();											//Enable Interrupts
		}
    }
	return 0;
}