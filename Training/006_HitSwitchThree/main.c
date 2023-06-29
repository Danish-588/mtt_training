#include <tm4c123gh6pge.h>
#include <stdint.h>
int main(void)
{
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6;  // GPIO Run Mode Clock On (PORTG)
    GPIO_PORTG_DIR_R  = 240;
    GPIO_PORTG_DEN_R  = 255;
    GPIO_PORTG_PUR_R  = 7;
    while(1)
        {
            GPIO_PORTG_DATA_R = (GPIO_PORTG_DATA_R & 15) |( (GPIO_PORTG_DATA_R&1)<<4 | (GPIO_PORTG_DATA_R&2)<<4 | (GPIO_PORTG_DATA_R&4)<<4 )^ 112;
        }
}
