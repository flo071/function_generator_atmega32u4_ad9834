/*
Created by flo071
*/
#define SETTINGSL  7
#define SETTINGSM 10

int settings(void){
	switch(wc){
		case 1: _delay_ms(KeyT); setcursor(wc); settings_signalform(); break;
		case 2: _delay_ms(KeyT); setcursor(wc); settings_freqency();   break;
		case 3: _delay_ms(KeyT); setcursor(wc); settings_amplitude();  break;
		case 4: _delay_ms(KeyT); setcursor(wc); settings_offset();     break;
	}
}

int settings_signalform(void){
	while(1){
		switch(keypad()){
			case  1: _delay_ms(KeyT); lcd_clr_line(wc); lcd_setcursor(8,wc); lcd_string("Sine");      break;
			case  2: _delay_ms(KeyT); lcd_clr_line(wc); lcd_setcursor(8,wc); lcd_string("Triangle");  break;
			case  3: _delay_ms(KeyT); lcd_clr_line(wc); lcd_setcursor(8,wc); lcd_string("Rectangle"); break;
			case 10: _delay_ms(KeyT); del_cursor(wc); 	wc=0;		 		 menu_nav(); 			  break;
			case 20: del_cursor(wc); wc=1; settings(); break;
			case 21: del_cursor(wc); wc=2; settings(); break;
			case 22: del_cursor(wc); wc=3; settings(); break;
			case 23: del_cursor(wc); wc=4; settings(); break;
			} 
		}
}

int settings_freqency(void){
	while(1){
		switch(keypad()){
			case  2: _delay_ms(KeyT); frq=frq+10; 	  lcd_clr_line(wc);	break;
			case  5: _delay_ms(KeyT); frq=frq-10; 	  lcd_clr_line(wc);	break;
			case 10: _delay_ms(KeyT); del_cursor(wc); wc=0; menu_nav(); break;
			case 20: del_cursor(wc); wc=1; settings(); break;
			case 21: del_cursor(wc); wc=2; settings(); break;
			case 22: del_cursor(wc); wc=3; settings(); break;
			case 23: del_cursor(wc); wc=4; settings(); break;
		}
		if(frq>=18000000){
			frq=10;
		} else if(frq<=0){
			frq=18000000;
		}
		print_unit();
		lcd_setcursor(11,wc);
		char frq_buffer[32];
		sprintf(frq_buffer, "%d", frq);
		lcd_string(frq_buffer);
	}
	
}

int settings_amplitude(void){
	while(1){
		switch(keypad()){
			case  2: _delay_ms(KeyT); amp++; 	  	  lcd_clr_line(wc);	break;
			case  5: _delay_ms(KeyT); amp--; 	  	  lcd_clr_line(wc);	break;
			case 10: _delay_ms(KeyT); del_cursor(wc); wc=0; menu_nav(); break;
			case 20: del_cursor(wc); wc=1; settings(); break;
			case 21: del_cursor(wc); wc=2; settings(); break;
			case 22: del_cursor(wc); wc=3; settings(); break;
			case 23: del_cursor(wc); wc=4; settings(); break;
		}
		if(amp>=25){
			amp=1;
		} else if(frq<=0){
			amp=24;
		}
		lcd_setcursor(11,wc);
		char amp_buffer[10];
		sprintf(amp_buffer, "%d", amp);
		lcd_string(amp_buffer);
	}
}

int settings_offset(void){
	while(1){
		switch(keypad()){
			case  2: _delay_ms(KeyT); ofs++; 	  	  lcd_clr_line(wc);	break;
			case  5: _delay_ms(KeyT); ofs--; 	  	  lcd_clr_line(wc);	break;
			case 10: _delay_ms(KeyT); del_cursor(wc); wc=0; menu_nav(); break;
			case 20: del_cursor(wc); wc=1; settings(); break;
			case 21: del_cursor(wc); wc=2; settings(); break;
			case 22: del_cursor(wc); wc=3; settings(); break;
			case 23: del_cursor(wc); wc=4; settings(); break;
		}
		if(ofs>=25){
			ofs=-24;
		} else if(ofs<=-25){
			ofs=24;
		}
		lcd_setcursor(11,wc);
		char ofs_buffer[10];
		sprintf(ofs_buffer, "%d", ofs);
		lcd_string(ofs_buffer);
	}
}