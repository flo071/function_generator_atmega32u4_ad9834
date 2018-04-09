/*
Created by flo071

Standard frequency of the generator on startup is:
1 kHz sine
*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "include/LCD/lcd.c"
#include "include/KEYPAD/keypad.c"
#include "include/SIGNAL/signal.c"

int value = 0;

int setup(void) {
	//Disable JTAG
	MCUCR =  (1 << JTD);
	MCUCR =  (1 << JTD);
	//Enable LCD
	LCD_setup();
	//Enable SPI
	SPI_setup();
	//Enable Keypad
	KEYPAD_setup();
	startup_signal();
}

int main(void) {
	setup();
	while (1) {
		value = 0;
		keypad_display_test();
	}
}

/*int menu_layout() {
	lcd_setcursor(0,0);
    lcd_string("Signalform:       [A]");
    lcd_setcursor(0,1);
    lcd_string("Frequency:        [B]");
    lcd_setcursor(0,2);
    lcd_string("Amplitude:        [C]");
    lcd_setcursor(0,3);
    lcd_string("Offset:           [D]");
}*/

int keypad_display_test() {
	keypad();
	value = keypad();
	switch (value) {
	case  0: lcd_string(" 0 has been pressed.");
	case  1: lcd_string("    Sine output     "); signal_sin();
	case  2: lcd_string("  Triangle output   "); signal_tri();
	case  3: lcd_string("  Rectangle output  "); signal_rect();
	case  4: lcd_string(" 4 has been pressed.");
	case  5: lcd_string(" 5 has been pressed.");
	case  6: lcd_string(" 6 has been pressed.");
	case  7: lcd_string(" 7 has been pressed.");
	case  8: lcd_string(" 8 has been pressed.");
	case  9: lcd_string(" 9 has been pressed.");
	case 10: lcd_string(" * has been pressed.");
	case 11: lcd_string(" 0 has been pressed.");
	case 12: lcd_string(" # has been pressed.");
	case 13: lcd_string(" A has been pressed.");
	case 14: lcd_string(" B has been pressed.");
	case 15: lcd_string(" C has been pressed.");
	case 16: lcd_string(" D has been pressed.");
	}
}
