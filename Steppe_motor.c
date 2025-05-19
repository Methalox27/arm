#include <LPC21xx.H>

void clock_wise(void);
void anti_clock_wise(void);

unsigned long int var1,var2;
unsigned int i=0,j=0,k=0;

int main (void)
{
  PINSEL0 = 0x00FFFFFF;   //P0.12 to P0.15 GPIO
  IODIR   = 0x0000F000;   //P0.12 to P0.15 output

  while(1)
  {
    for(j=0;j<500;j++);   // 20 times in Clock wise Rotation
    clock_wise();

    for(k=0;k<600;k++);   // Delay to show anti-clock Rotation

    for(j=0;j<500;j++);   // 20 times in Anti Clock wise
    anti_clock_wise();

    for(k=0;k<600;k++);   // Delay to show clock Rotation
  }   // End of while(1)
}   // End of main

void clock_wise(void)
{
  var1 = 0x00008000;   //For Clockwise
  for(i=0;i<=3;i++)   // for A B C D Stepping
  {
    var1 = var1<<1;   //For Clockwise
    IO0PIN = var1;
    for(k=0;k<5000;k++);  //for step speed variation
  }
}

void anti_clock_wise(void)
{
  var1 = 0x00010000;   //For Anticlockwise
  for(i=0;i<=3;i++)   // for A B C D Stepping
  {
    var1 = var1>>1;   //For Anticlockwise
    IO0PIN = var1;
    for(k=0;k<5000;k++);  //for step speed variation
  }
}