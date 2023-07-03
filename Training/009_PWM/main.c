#include <tm4c123gh6pge.h>
#include <stdint.h>


int main(void)
{
    //clock
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6;
    SYSCTL_RCGC0_R = 0x100000;            // PWM Clock
    SYSCTL_RCC_R |= 1;
    SYSCTL_RCC_R |= SYSCTL_RCC_USESYSDIV;    //| SYSCTL_RCC_PWMDIV_2?

    //configuring
    GPIO_PORTG_DIR_R  = 0x04;
    GPIO_PORTG_DEN_R  = 0x04;
    GPIO_PORTG_AFSEL_R = 0X04;
    GPIO_PORTG_PCTL_R = GPIO_PCTL_PG2_M1PWM0;
    GPIO_PORTG_AMSEL_R = 0X4;

    //configuring for countdown mode
    PWM0_CTL_R = 0x00000000;
    PWM0_0_GENA_R = 0x0000008C;
    PWM0_0_GENB_R = 0x0000080C;

    //generating
    PWM0_0_LOAD_R = 0x7C; //for 80KHz time period=125 microseconds therefore 124
    PWM0_0_CMPA_R = 0x3E; //for 50% duty cycle
    PWM0_CTL_R = 0x00000001; //starting the timer in pwm0
    PWM0_ENABLE_R = 0x00000001; //enable outputs

    while (1)
    {

    }
}
