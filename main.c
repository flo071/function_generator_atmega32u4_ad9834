/*
Created by flo071
*/
#define F_CPU 10000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

int x=0;

int main(void){
	init();

    while(x=0){
    	k1_sig();
		
    }
while(x=1){
    //do nothing
}
}

int init(void){
	//Disable JTAG
	MCUCR =  (1<<JTD);
    MCUCR =  (1<<JTD);
    //Setup Pins for SPI
	DDRB  |=  (1<<PB0); //SlaveSelect
	DDRB  |=  (1<<PB1); //CLK
	DDRB  |=  (1<<PB2); //MOSI
	DDRB  &= ~(1<<PB3); //MISO
	DDRB  |=  (1<<PB4); //SS Dummy
	DDRB  |=  (1<<PB7); //SS for manual bit selection, like 16bit here
	PORTB |=  (1<<PB7); //SS active low set high
	//Setup SPI
	//SPI init
	SPCR &= ~(1<<DORD); //Data order MSB first
	SPCR |=  (1<<MSTR); //Master mode
	SPCR &= ~(1<<CPOL); //sclk rising edge
	SPCR &= ~(1<<CPHA); //sclk phase 
	SPCR |=  (1<<SPR1); //sclk prescaler /64
	SPCR |=  (1<<SPR0); //sclk prescaler /64
	SPSR |=  (1<<SPI2X);//sclk prescaler /64
}

int k1_sig(){
	x=1;

	//control register write 
	SPDR = 0b00000001;
	PORTB &= ~(1<<PB7); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = 0b00000000;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	PORTB |= (1<<PB7); 	//SlaveSelect set high

	//tell ad9834 to receive 28 bits
	SPDR = 0b00100001;
	PORTB &= ~(1<<PB7); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = 0b00000000;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	PORTB |= (1<<PB7); 	//SlaveSelect set high

	//write to freq 0 register 1kHz
	SPDR = 0b01000000;
	PORTB &= ~(1<<PB7); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = 0b00000000;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = 0b01001101;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = 0b11111011;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);	
	PORTB |= (1<<PB7); 	//SlaveSelect set high

	//write to freq 1 register 1kHz
	SPDR = 0b01000000;
	PORTB &= ~(1<<PB7); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = 0b00000000;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = 0b01001101;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = 0b11111011;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);	
	PORTB |= (1<<PB7); 	//SlaveSelect set high

	//phase 0
	SPDR = 0b11000000;
	PORTB &= ~(1<<PB7); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = 0b00000000;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	PORTB |= (1<<PB7); 	//SlaveSelect set high

	//phase 1
	SPDR = 0b11000000;
	PORTB &= ~(1<<PB7); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = 0b00000000;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	PORTB |= (1<<PB7); 	//SlaveSelect set high

	//freq 1 output
	SPDR = 0b00001100;
	PORTB &= ~(1<<PB7); //SlaveSelect set low, to let ad9834 know we want to send something
	_delay_ms(1);		//wait for SS to be set to low
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	SPDR = 0b00000000;
	SPCR |=  (1<<SPE); 	//SPI enable (start data tranfer)
	_delay_ms(10);		//wait for the third 8 bit to be send
	PORTB |= (1<<PB7); 	//SlaveSelect set high

    return x;
}