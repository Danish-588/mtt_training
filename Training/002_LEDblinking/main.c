#include <tm4c123gh6pge.h>
#include <stdint.h>
int main(void)
{
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6;  // GPIO Run Mode Clock On (PORTG)
    GPIO_PORTG_DIR_R  = 1;                   // GPIO Pins to Output (PORTG)
    GPIO_PORTG_DEN_R  = 1;                   // GPIO digital Enable (PORTG)
    int i =0, a = 0;
    while(1)
        {
            if(i==0)
            {   GPIO_PORTG_DATA_R = 1;
                i++;            }
            else
            {   GPIO_PORTG_DATA_R = 0;
                i--;            }
            for(a = 0; a < 1000000; a++){}
        }
}
