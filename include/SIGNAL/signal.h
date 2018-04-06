/*
Created by flo071

SPI needs to be configured to send LSB first
Only using Frequency 0 and Phase 0 Register here

Selecting what register to write:
DB15 DB14 DB13
 0    0    X    Control Bits
 0    1    X    Frequency 0 Register
 1    0    X    Frequency 1 Register
 1    1    0    Phase 0 Register
 1    1    1    Phase 1 Register
*/



//control word reset
#define CTRLw1  0b00000000
#define CTRLw2  0b00100001

//frequency 1 reg
#define FRQ0    0b01000000

//frequency 2 reg
#define FRQ1    0b10000000 

//phase 1 reg
#define PHS0    0b11000000

//phase 2 reg
#define PHS1    0b11100000

//start output sin
#define OUTsin1 0b00000000
#define OUTsin2 0b00100000

//start output tri
#define OUTtri1 0b00000010
#define OUTtri2 0b00100000

//start output rect
#define OUTrect1 0b00111000
#define OUTrect2 0b00100000

