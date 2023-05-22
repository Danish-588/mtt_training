#include <stdint.h>
#include <tm4c123gh6pge.h>

int main(void)
{
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6;
    GPIO_PORTG_DIR_R  = 255;
    GPIO_PORTG_DEN_R  = 255;
    int i=0,a=0;
    while (1)
    {
        GPIO_PORTG_DATA_R = (1<<(i%8))|(1<<(7-(i++%8)));      //pattern
        for(a = 0; a < 400000; a++){}                       //delay
    }
}
