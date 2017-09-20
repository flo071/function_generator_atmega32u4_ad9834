#include <avr/io.h>

void spi_init(void)
{
  sbi(DDRB, 4);
  sbi(DDRB, 5);
  cbi(DDRB, 6);
  sbi(DDRB, 7);
  sbi(SPCR, 0);
  sbi(SPCR, 4);
  sbi(SPCR, 6);
}

void spi_send(uint8_t data)
{
  SPDR = data;
  while(bit_is_clear(SPSR, 7))
  {

  }
}