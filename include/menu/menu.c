/*
Created by flo071
*/
menu_nav(void){
	while(1){
		if((PIND | Key1) == Key1){
			wc--;
			_delay_ms(KeyT);
			if(wc>=5){
				wc=1;
			} else if(wc<=0){
				wc=4;
			}
			switch(wc){
				case 1: setcursor(1); del_cursor(2); del_cursor(3); del_cursor(4); break;
				case 2: setcursor(2); del_cursor(1); del_cursor(3); del_cursor(4); break;
				case 3: setcursor(3); del_cursor(1); del_cursor(2); del_cursor(4); break;
				case 4: setcursor(4); del_cursor(1); del_cursor(2); del_cursor(3); break;
			}
		} else if((PIND | Key4) == Key4){
			wc++;
			_delay_ms(KeyT);
			if(wc>=5){
				wc=1;
			} else if(wc<=0){
				wc=4;
			}
			switch(wc){
				case 1: setcursor(1); del_cursor(2); del_cursor(3); del_cursor(4); break;
				case 2: setcursor(2); del_cursor(1); del_cursor(3); del_cursor(4); break;
				case 3: setcursor(3); del_cursor(1); del_cursor(2); del_cursor(4); break;
				case 4: setcursor(4); del_cursor(1); del_cursor(2); del_cursor(3); break;
			}
		}
		settings();
	}
}

int menu_layout(void){
    lcd_setcursor(0,1);
    lcd_string("Signal: Sine");
    lcd_setcursor(0,2);
    lcd_string("Frequency: 10");
    lcd_setcursor(0,3);
    lcd_string("Amplitude: 5");
    lcd_setcursor(0,4);
    lcd_string("Offset:    0");
    _delay_ms(1000);
    setcursor(1);
}

int print_unit(void){
    lcd_setcursor(18,1); lcd_string(" ");
    lcd_setcursor(17,2); lcd_string("Hz");
    lcd_setcursor(16,3); lcd_string("Vpp");
    lcd_setcursor(16,4); lcd_string("Vdc");
}