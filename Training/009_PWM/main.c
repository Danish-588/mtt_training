#include <tm4c123gh6pge.h>
#include <stdint.h>


int main(void)
{
    //clock
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6;
    SYSCTL_RCGC0_R |= 0x100000;            // PWM Clock
    SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
    SYSCTL_RCC_R &= 0xFFFF1FFF;       // /2divider    clearing 3 bits for clock div

    //configuring
    GPIO_PORTG_DEN_R  = 0x04;
    GPIO_PORTG_DIR_R = 0X04;
    GPIO_PORTG_AFSEL_R |= 0X04; //associated pin fns
    GPIO_PORTG_PCTL_R = GPIO_PCTL_PG2_M1PWM0;

    //configuring for count down mode
    PWM1_CTL_R = 0; //clearing
    PWM1_0_GENA_R = PWM_1_GENA_ACTCMPAD_ZERO|PWM_1_GENA_ACTLOAD_M;

    //generating
    PWM1_0_LOAD_R = 1249;      //31.25*40 = 1250-1 1249
    PWM1_0_CMPA_R = 625;      //for 50% duty cycle
    PWM1_CTL_R |= PWM_1_CTL_ENABLE|PWM_1_CTL_MODE;           //starting the timer in pwm0
    PWM1_ENABLE_R |= 0xF;        //enable outputs

    //for 32KHz frequency, time period = 31.25 microseconds
    //PWM clock is half of system clock = 40 Mhz

    while (1)
    {

    }
}
