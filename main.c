#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "LCD/lcd.c"
#include "SPI/spi.c"
//#include "keyboard/keyboard.c"

int main(void){
	PORTB=0xFF;
    lcd_init();
    for(;;){
    	
    }
	return 0;
}