#include <tm4c123gh6pge.h>
#include <stdint.h>
int main(void)
{
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6;  // GPIO Run Mode Clock On (PORTG)
    GPIO_PORTG_DIR_R  = 48;
    GPIO_PORTG_DEN_R  = 255;                 // GPIO digital Enable (PORTG)
    GPIO_PORTG_PUR_R  = 3;
    while(1)
        {
            if((GPIO_PORTG_DATA_R & 1) == 0)
                GPIO_PORTG_DATA_R |=(1<<4);
            else(GPIO_PORTG_DATA_R &=(0<<4));
            if((GPIO_PORTG_DATA_R & 2) == 0)
                GPIO_PORTG_DATA_R |=(1<<5);
            else(GPIO_PORTG_DATA_R &=(0<<5));       //to do ternaru
        }
}
