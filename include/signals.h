/*
Created by flo071

Define strings for signals
AD9834 needs 16bit input to setup the signal
those bits are defined in this file
*/

#define k1_1   0b00110001 //first  8 bits of string for 1kHz Signal
#define k1_2   0b10101000 //second 8 bits of string for 1kHz Signal
#define k2_1   0b00110001 //first  8 bits of string for 2kHz Signal
#define k2_2   0b10101000 //second 8 bits of string for 2kHz Signal
#define k5_1   0b00110001 //first  8 bits of string for 5kHz Signal
#define k5_2   0b10101000 //second 8 bits of string for 5kHz Signal
#define k10_1  0b00110001 //first  8 bits of string for 10kHz Signal
#define k10_2  0b10101000 //second 8 bits of string for 10kHz Signal
#define k50_1  0b00110001 //first  8 bits of string for 50kHz Signal
#define k50_2  0b10101000 //second 8 bits of string for 50kHz Signal
#define k100_1 0b00110001 //first  8 bits of string for 100kHz Signal
#define k100_2 0b10101000 //second 8 bits of string for 100kHz Signal
#define k500_1 0b00110001 //first  8 bits of string for 500kHz Signal
#define k500_2 0b10101000 //second 8 bits of string for 500kHz Signal
#define M1_1   0b00110001 //first  8 bits of string for 1MHz Signal
#define M1_2   0b10101000 //second 8 bits of string for 1MHz Signal
#define M10_1  0b00110001 //first  8 bits of string for 10MHz Signal
#define M10_2  0b10101000 //second 8 bits of string for 10MHz Signal
#define M20_1  0b00110001 //first  8 bits of string for 20MHz Signal
#define M20_2  0b10101000 //second 8 bits of string for 20MHz Signal
#define M36_1  0b00110001 //first  8 bits of string for 36MHz Signal
#define M36_2  0b10101000 //second 8 bits of string for 36MHz Signal
#define RESET  0b00000000 //Reset the output to not send signals