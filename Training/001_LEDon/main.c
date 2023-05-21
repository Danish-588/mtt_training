#include <tm4c123gh6pge.h>
#include <stdint.h>

int main(void)
{
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6; // GPIO Run Mode Clock
    GPIO_PORTA_DIR_R  = 85;                 // GPIO to Output (PORTG)
    GPIO_PORTA_DEN_R  = 85;                 // GPIO Digital Enable (PORTG)
    GPIO_PORTA_DATA_R = 85;                 // GPIO Value on (PORTG)

    while(1){}
}
