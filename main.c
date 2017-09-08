#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd/LCD.c"
#include "keyboard/keyboard.c"
int main(void){
    lcd_init();
    PORTB=0xFF;
    for(;;){
    	void SPI_MasterInit(void){
			DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
			SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
		}
		void SPI_MasterTransmit(char cData){
			SPDR = cData;
			while(!(SPSR & (1<<SPIF)));
		}
    }
	return 0;
}