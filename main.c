#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "LCD/lcd.c"
#include "SPI/spi.c"
#include "keyboard/keyboard.c"

int main(void){
    lcd_init();
    lcd_setcursor(6,2);
    lcd_string("function");
    lcd_setcursor(7,3);
    lcd_string("generator");
    for(;;){
    	keyboard();
        if(keyboard()<=10){
            lcd_setcursor(0,1);
            char out_d[30];
            itoa(keyboard(), out_d, 30);
            lcd_string(out_d);
        }
        if(keyboard()>=10){
            if(keyboard()==10){
                lcd_setcursor(0,1);
                lcd_string("Stop");
                _delay_ms(1000);
                lcd_clear();
            }
            if(keyboard()==12){
                lcd_setcursor(0,1);
                lcd_string("Start");
                _delay_ms(1000);
                lcd_clear();
            }
        }
    }
	return 0;
}