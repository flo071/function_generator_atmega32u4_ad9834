/*
Created by flo071
*/
int settings(void){
	if(((PIND | Key2) == Key2) && wc == 1){
		_delay_ms(KeyT);
		setcursor_sel(wc);
		settings_signalform();
	} else if(((PIND | Key2) == Key2) && wc == 2){
		_delay_ms(KeyT);
		setcursor_sel(wc);
		settings_freqency();
	} else if(((PIND | Key2) == Key2) && wc == 3){
		_delay_ms(KeyT);
		setcursor_sel(wc);
		settings_amplitude();
	} else if(((PIND | Key2) == Key2) && wc == 4){
		_delay_ms(KeyT);
		setcursor_sel(wc);
		settings_offset();
	}
}

int settings_signalform(void){
	while((PIND | Key3) != Key3){
		if((PIND | Key1) == Key1){
			setsign--;
			_delay_ms(KeyT);
			if(setsign>=4){
				setsign=1;
			} else if(setsign<=0){
				setsign=3;
			}
			switch(setsign){
				case 1: lcd_clr_line(1); lcd_setcursor(8,1); lcd_string("Sine");      break;
				case 2: lcd_clr_line(1); lcd_setcursor(8,1); lcd_string("Triangle");  break;
				case 3: lcd_clr_line(1); lcd_setcursor(8,1); lcd_string("Rectangle"); break;
			}
		} else if((PIND | Key4) == Key4){
			setsign++;
			_delay_ms(KeyT);
			if(setsign>=4){
				setsign=1;
			} else if(setsign<=0){
				setsign=3;
			}
			switch(setsign){
				case 1: lcd_clr_line(1); lcd_setcursor(8,1); lcd_string("Sine");      break;
				case 2: lcd_clr_line(1); lcd_setcursor(8,1); lcd_string("Triangle");  break;
				case 3: lcd_clr_line(1); lcd_setcursor(8,1); lcd_string("Rectangle"); break;
			}
		}
	}
	setcursor(wc);
}

int settings_freqency(void){
	while((PIND | Key3) != Key3){
		if((PIND | Key1) == Key1){
			frq=frq+10;
			_delay_ms(KeyT);
			if(frq>=18000000){
				frq=10;
			} else if(frq<=0){
				frq=18000000;
			}
			lcd_clr_line(wc);
		} else if((PIND | Key4) == Key4){
			frq=frq-10;
			_delay_ms(KeyT);
			if(frq>=18000000){
				frq=10;
			} else if(frq<=0){
				frq=18000000;
			}
			lcd_clr_line(wc);
		}
		if(frq>=1000){
			frq_s=frq/1000;
			lcd_setcursor(16,wc);
			lcd_string("k");
		} else if(frq>=1000000){
			frq_s=frq/1000000;
			lcd_setcursor(16,wc);
			lcd_string("M");
		} else if(frq<<1000){
			lcd_setcursor(16,wc);
			lcd_string(" ");
		}
		lcd_setcursor(11,wc);
		char frq_buffer[32];
		sprintf(frq_buffer, "%d", frq);
		lcd_string(frq_buffer);
	}
	setcursor(wc);
}

int settings_amplitude(void){
	while((PIND | Key3) != Key3){
		if((PIND | Key1) == Key1){
			amp++;
			_delay_ms(KeyT);
			if(amp>=25){
				amp=1;
			} else if(frq<=0){
				amp=24;
			}
		lcd_clr_line(3);
		lcd_setcursor(11,wc);
		char amp_buffer[10];
		sprintf(amp_buffer, "%d", amp);
		lcd_string(amp_buffer);
		} else if((PIND | Key4) == Key4){
			amp--;
			_delay_ms(KeyT);
			if(amp>=25){
				amp=1;
			} else if(amp<=0){
				amp=24;
			}
		lcd_clr_line(3);
		lcd_setcursor(11,wc);
		char amp_buffer[10];
		sprintf(amp_buffer, "%d", amp);
		lcd_string(amp_buffer);
		}
	}
	setcursor(wc);
}

int settings_offset(void){
	while((PIND | Key3) != Key3){
		if((PIND | Key1) == Key1){
			ofs=ofs+1;
			_delay_ms(KeyT);
			if(ofs>=25){
				ofs=-24;
			} else if(ofs<=-25){
				ofs=24;
			}
		lcd_clr_line(4);
		lcd_setcursor(11,wc);
		char ofs_buffer[10];
		sprintf(ofs_buffer, "%d", ofs);
		lcd_string(ofs_buffer);
		} else if((PIND | Key4) == Key4){
			ofs=ofs-1;
			_delay_ms(KeyT);
			if(ofs>=25){
				ofs=-24;
			} else if(ofs<=-25){
				ofs=24;
			}
		lcd_clr_line(4);
		lcd_setcursor(11,wc);
		char ofs_buffer[10];
		sprintf(ofs_buffer, "%d", ofs);
		lcd_string(ofs_buffer);
		}
	}
	setcursor(wc);
}