#include <avr/io.h>

void SPI_MasterInit(void){
	DDRB = (1<<PB2)|(1<<PB1);
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_MasterTransmit(char cData){
	SPDR = cData;
	while(!(SPSR & (1<<SPIF)));
}