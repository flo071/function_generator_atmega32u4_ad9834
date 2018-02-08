/*
Created by flo071

Define strings for signals
AD9834 needs 16bit input to setup the signal
this input is split up in 2 8bit messages
those bits are defined in this file

Bits (right to left): 
		1.  always 0
		2.  Mode Bit
		3.  always 0
		4.  DIV2
		5.  SIGN/PIB
		6.  OPBITEN
		7.  SLEEP 12
		8.  SLEEP 1
		9.  RESET
		10. PIN/SW
		11. PSEL
		12. FSEL
		13. HLB 
		14. B28
		15. always 0
		16. always 0

		| OPBITEN | MODE |  OUTPUT  |
		|    0    |  0   |  Sine    |
		|    0    |  1   | Triangle |
*/


//TODO correct strings for the signals
//Sin
#define sk1_1   0b00110001 //first  8 bits of string for 1kHz Signal
#define sk1_2   0b10001000 //second 8 bits of string for 1kHz Signal

#define sk2_1   0b00110001 //first  8 bits of string for 2kHz Signal
#define sk2_2   0b10001000 //second 8 bits of string for 2kHz Signal

#define sk5_1   0b00110001 //first  8 bits of string for 5kHz Signal
#define sk5_2   0b10001000 //second 8 bits of string for 5kHz Signal

#define sk10_1  0b00110001 //first  8 bits of string for 10kHz Signal
#define sk10_2  0b10001000 //second 8 bits of string for 10kHz Signal

#define sk50_1  0b00110001 //first  8 bits of string for 50kHz Signal
#define sk50_2  0b10001000 //second 8 bits of string for 50kHz Signal

#define sk100_1 0b00110001 //first  8 bits of string for 100kHz Signal
#define sk100_2 0b10001000 //second 8 bits of string for 100kHz Signal

#define sk500_1 0b00110001 //first  8 bits of string for 500kHz Signal
#define sk500_2 0b10001000 //second 8 bits of string for 500kHz Signal

#define sM1_1   0b00110001 //first  8 bits of string for 1MHz Signal
#define sM1_2   0b10001000 //second 8 bits of string for 1MHz Signal

#define sM10_1  0b00110001 //first  8 bits of string for 10MHz Signal
#define sM10_2  0b10001000 //second 8 bits of string for 10MHz Signal

#define sM20_1  0b00110001 //first  8 bits of string for 20MHz Signal
#define sM20_2  0b10001000 //second 8 bits of string for 20MHz Signal

#define sM36_1  0b00110001 //first  8 bits of string for 36MHz Signal
#define sM36_2  0b10001000 //second 8 bits of string for 36MHz Signal

//Tri
#define tk1_1   0b00110001 //first  8 bits of string for 1kHz Signal
#define tk1_2   0b10101000 //second 8 bits of string for 1kHz Signal

#define tk2_1   0b00110001 //first  8 bits of string for 2kHz Signal
#define tk2_2   0b10101000 //second 8 bits of string for 2kHz Signal

#define tk5_1   0b00110001 //first  8 bits of string for 5kHz Signal
#define tk5_2   0b10101000 //second 8 bits of string for 5kHz Signal

#define tk10_1  0b00110001 //first  8 bits of string for 10kHz Signal
#define tk10_2  0b10101000 //second 8 bits of string for 10kHz Signal

#define tk50_1  0b00110001 //first  8 bits of string for 50kHz Signal
#define tk50_2  0b10101000 //second 8 bits of string for 50kHz Signal

#define tk100_1 0b00110001 //first  8 bits of string for 100kHz Signal
#define tk100_2 0b10101000 //second 8 bits of string for 100kHz Signal

#define tk500_1 0b00110001 //first  8 bits of string for 500kHz Signal
#define tk500_2 0b10101000 //second 8 bits of string for 500kHz Signal

#define tM1_1   0b00110001 //first  8 bits of string for 1MHz Signal
#define tM1_2   0b10101000 //second 8 bits of string for 1MHz Signal

#define tM10_1  0b00110001 //first  8 bits of string for 10MHz Signal
#define tM10_2  0b10101000 //second 8 bits of string for 10MHz Signal

#define tM20_1  0b00110001 //first  8 bits of string for 20MHz Signal
#define tM20_2  0b10101000 //second 8 bits of string for 20MHz Signal

#define tM36_1  0b00110001 //first  8 bits of string for 36MHz Signal
#define tM36_2  0b10101000 //second 8 bits of string for 36MHz Signal

#define RESET  0b00000000 //Reset the output to not send signals