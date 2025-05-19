#include <LPC21xx.h>

unsigned int delay;

int main () {

  PINSEL1 = 0x00000000 ;  // Configure P0.16 to P0.31 as GPIO
  IODIR   = 0x00FF0000 ;  // Configure P0.16 to P0.23 as Output
  IO0SET  = 0x00FF0000 ;

  while(1)
  {
    IO0CLR = 0x00020000;  // CLEAR (0) P0.17, LED ON
    for(delay=0; delay<500000; delay++); // delay
    IO0SET = 0x00020000;  // SET (1) P0.17, LED OFF
    for(delay=0; delay<500000; delay++); // delay
  }
}