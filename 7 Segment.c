#include <LPC21xx.h>
unsigned int delay;
unsigned int Switchcount = 0;

unsigned int Disp[16] = {
    0x003F0000, 0x00060000, 0x005B0000, 0x004F0000, 0x00660000, 0x006D0000,
    0x007D0000, 0x00070000, 0x007F0000, 0x006F0000, 0x00770000, 0x007C0000,
    0x00390000, 0x005E0000, 0x00790000, 0x00710000
};

#define SELDISP1 0x10000000  // P0.28
#define SELDISP2 0x20000000  // P0.29
#define SELDISP3 0x40000000  // P0.30
#define SELDISP4 0x80000000  // P0.31
#define ALLDISP  0xF0000000  // Select all display
#define DATAPORT 0x00FF0000  // P0.16 to P0.23 Data lines connected to drive Seven Segments

int main(void) {
    PINSEL0 = 0x00000000;
    PINSEL1 = 0x00000000;
    IODIR   = 0xFFF0000;
    IO1DIR  = 0x00000000;

    while (1) {
        IO0SET  |= ALLDISP;    // select all digits
        IO0CLR  = 0x00FF0000;  // clear the data lines to 7-segment displays
        IO0SET  = Disp[Switchcount]; // get the 7-segment display value from the array

        if (!(IO1PIN & 0x00800000)) // if the key is pressed
        {
            for (delay = 0; delay < 100000; delay++); // delay
            
            if ((IO1PIN & 0x00800000))  // check to see if key has been released
            {
                Switchcount++;
                if (Switchcount == 0x10) // 0 to F has been displayed ? go back to 0
                {
                    Switchcount = 0;
                    IO0CLR    = 0xF0F00000;
                }
            }
        }
    }
}
