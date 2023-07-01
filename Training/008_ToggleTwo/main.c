#include <tm4c123gh6pge.h>
#include <stdint.h>

volatile int old_value=0,i=0;

int main(void)
{
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6;
    GPIO_PORTG_DIR_R  = 0x30;
    GPIO_PORTG_DEN_R  = 0xFF;
    GPIO_PORTG_PUR_R  = 0x3;

while(1)
    {
        if(i>10000)     // smart delay to avoid bouncing
        i=0;            // reset i so it goes on constantly
        i++;
        if (i==5)       // execute the code only once every 10000 clock cycles
        {
            GPIO_PORTG_DATA_R = GPIO_PORTG_DATA_R ^ (((~GPIO_PORTG_DATA_R & old_value)&0x0F)<< 4); //Toggle when going from 0 to 1
            old_value = GPIO_PORTG_DATA_R & 0x0F; // Extracting only the input bits
        }
    }
}
