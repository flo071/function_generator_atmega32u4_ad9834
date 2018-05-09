/*
Created by flo071
*/
menu_nav(void){
	while(1){
		switch(keypad()){
			case 20: wc=1; break;
			case 21: wc=2; break;
			case 22: wc=3; break;
			case 23: wc=4; break;
		}
		settings();
	}
}

int menu_layout(void){
    lcd_setcursor(0,1);
    lcd_string("Signal: Sine      A ");
    lcd_setcursor(0,2);
    lcd_string("Frequency: 10     B ");
    lcd_setcursor(0,3);
    lcd_string("Amplitude: 5      C ");
    lcd_setcursor(0,4);
    lcd_string("Offset:    0      D ");
   	print_unit();
}

int print_unit(void){
    lcd_setcursor(15,2); lcd_string("Hz");
    lcd_setcursor(14,3); lcd_string("Vpp");
    lcd_setcursor(14,4); lcd_string("Vdc");
}