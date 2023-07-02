#include <tm4c123gh6pge.h>
#include <stdint.h>


int main(void)
{
    //clock
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6;  // GPIO Run Mode Clock On (PORTG)
    SYSCTL_RCGC0_R = 0x0010.0000;            // PWM Clock
    SYSCTL_RCC_R = SYSCTL_RCC_USESYSDIV | SYSCTL_RCC_PWMDIV_2; // Configure the Run-Mode Clock Configuration (RCC) register in the System Control module to use the PWM divide (USEPWMDIV) and set the divider (PWMDIV) to divide by 2 (000).

    //configuring
    GPIO_PORTG_DIR_R  = 0x04;
    GPIO_PORTG_DEN_R  = 0x04;  // configured by clearing the DEN bit in the GPIO Digital Enable (GPIODEN)
    GPIO_PORTG_AFSEL_R = 0X04; // The digital alternate hardware functions are enabled by setting the appropriate bit in the GPIO Alternate Function Select (GPIOAFSEL)
    GPIO_PORTG_PCTL_R = GPIO_PCTL_PG2_M1PWM0;  // and configuring the PMCx bit field in the GPIO Port Control (GPIOPCTL) register to the numeric encoding shown in the table below
    GPIO_PORTG_AMSEL = 0X4;

    PWM0_CTL_R = 0x00000000;
    PWM0_0_GENA_R = 0x0000008C;
    PWM0_0_GENB_R = 0x0000080C;

    //setting
    PWM0_0_LOAD_R = ;


    PWM0_ENABLE_R =

    /*Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin. If an alternate
    pin is chosen for a bit, then the PMCx field must be programmed in the GPIOPCTL register for
    the specific peripheral required.*/



	return 0;
}
