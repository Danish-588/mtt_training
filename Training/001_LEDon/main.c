#include <tm4c123gh6pge.h>
#include <stdint.h>

int main(void)
{
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6; // GPIO Run Mode Clock
    GPIO_PORTG_DIR_R  = 1;                 // GPIO to Output (PORTG)
    GPIO_PORTG_DEN_R  = 1;                 // GPIO Digital Enable (PORTG)
    GPIO_PORTG_DATA_R = 1;                 // GPIO Value on (PORTG)

    while(1){}
}
