#include <tm4c123gh6pge.h>
#include <stdint.h>

int main(void)
{
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R0; // GPIO Run Mode Clock
    GPIO_PORTA_DIR_R  = 8; // GPIO Output (PORTA)
    GPIO_PORTA_DEN_R  = 8; // GPIO Digital Enable (PORTA)
    GPIO_PORTA_DATA_R = 8; // GPIO Value on (PORTA)

    return 0;
}
