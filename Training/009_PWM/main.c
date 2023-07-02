#include <tm4c123gh6pge.h>
#include <stdint.h>


int main(void)
{
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6 | ;  // GPIO Run Mode Clock On (PORTG)

    GPIO_PORTG_DIR_R  = 0x04;
    GPIO_PORTG_DEN_R  = 0x04;  // configured by clearing the DEN bit in the GPIO Digital Enable (GPIODEN)
    GPIO_PORTG_AFSEL_R = 0X04; // The digital alternate hardware functions are enabled by setting the appropriate bit in the GPIO Alternate Function Select (GPIOAFSEL)
    GPIO_PORTG_PCTL_R = 0x05;  // and configuring the PMCx bit field in the GPIO Port Control (GPIOPCTL) register to the numeric encoding shown in the table below
    GPIO_PORTG_AMSEL = 0X4;

    PWM0_0_LOAD_R = GPIO_PORTG_DATA_R;


    PWM0_ENABLE_R =

    /*Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin. If an alternate
    pin is chosen for a bit, then the PMCx field must be programmed in the GPIOPCTL register for
    the specific peripheral required.*/



	return 0;
}
