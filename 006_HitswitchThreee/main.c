#include <tm4c123gh6pge.h>
#include <stdint.h>
int main(void)
{
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6;  // GPIO Run Mode Clock On (PORTG)
    GPIO_PORTG_DIR_R  = 240;                  // p 4 to 7 output
    GPIO_PORTG_DEN_R  = 255;                 // GPIO digital Enable (PORTG)
    GPIO_PORTG_PUR_R  = 15;                   // p 0 to 3
    while(1)
        {
            if((GPIO_PORTG_DATA_R & 1) == 0)    // if p0 is low
                GPIO_PORTG_DATA_R |=(1<<4);     // turn on led p4
            else(GPIO_PORTG_DATA_R &=(0<<4));   // turn off led p4
            if((GPIO_PORTG_DATA_R & 2) == 0)    // if p1 is low
                GPIO_PORTG_DATA_R |=(1<<5);     // turn on led p5
            else(GPIO_PORTG_DATA_R &=(0<<5));   // turn off led p5
            if((GPIO_PORTG_DATA_R & 4) == 0)    // if p2 is low
                GPIO_PORTG_DATA_R |=(1<<6);     // turn on led p6
            else(GPIO_PORTG_DATA_R &=(0<<6));   // turn off led p6
            if((GPIO_PORTG_DATA_R & 8) == 0)    // if p3 is low
                GPIO_PORTG_DATA_R |=(1<<7);     // turn on led p7
            else(GPIO_PORTG_DATA_R &=(0<<7));   // turn off led p7
        }
}
