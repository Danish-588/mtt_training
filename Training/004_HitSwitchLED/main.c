#include <tm4c123gh6pge.h>
#include <stdint.h>
int main(void)
{
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6;  // GPIO Run Mode Clock On (PORTG)
    GPIO_PORTG_DIR_R  = 2;                   // GPIO Pin G0 to Input and G1 to Output
    GPIO_PORTG_DEN_R  = 255;                 // GPIO digital Enable (PORTG)
    GPIO_PORTG_PUR_R  = 1;
    while(1)
        {
            if(GPIO_PORTG_DATA_R&1)
                GPIO_PORTG_DATA_R = 0;
            else
                GPIO_PORTG_DATA_R|= 2;
        }
}
