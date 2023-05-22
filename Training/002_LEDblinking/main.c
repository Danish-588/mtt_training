#include <tm4c123gh6pge.h>
#include <stdint.h>
int main(void)
{
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6;  // GPIO Run Mode Clock On (PORTG)
    GPIO_PORTG_DIR_R  = 255;                   // GPIO Pins to Output (PORTG)
    GPIO_PORTG_DEN_R  = 255;                   // GPIO digital Enable (PORTG)
    int a = 0;
    while(1)
        {
            GPIO_PORTG_DATA_R = GPIO_PORTG_DATA_R ^ 1;
            for(a = 0; a < 1400000; a++){}    //delay nearly 1 second
        }
}
