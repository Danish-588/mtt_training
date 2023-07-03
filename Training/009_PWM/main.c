#include <tm4c123gh6pge.h>
#include <stdint.h>


int main(void)
{
    //clock
    SYSCTL_RCGC0_R |= SYSCTL_RCGC0_PWM0;            // PWM Clock
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOG;
    SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
    SYSCTL_RCC_R &= (~0x0000E000);       // /2divider    clearing 3 bits for clock div

    //configuring
    GPIO_PORTG_DIR_R = 0X04;
    GPIO_PORTG_AFSEL_R = 0X04; //associated pin fns
    GPIO_PORTG_DEN_R  = 0x04;
    GPIO_PORTG_PCTL_R = GPIO_PCTL_PG2_M1PWM0;

    //configuring for count down mode
    PWM0_CTL_R = 0; //clearing
    PWM0_0_GENA_R = PWM_0_GENA_ACTCMPAD_ZERO|PWM_0_GENA_ACTLOAD_M;

    //generating
    PWM0_0_LOAD_R = 1249;      //31.25*40 = 1250-1 1249
    PWM0_0_CMPA_R = 625;      //for 50% duty cycle
    PWM0_CTL_R |= PWM_0_CTL_ENABLE|PWM_0_CTL_MODE;           //starting the timer in pwm0
    PWM0_ENABLE_R |= PWM_ENABLE_PWM0EN;        //enable outputs
]
    //for 32KHz frequency, time period = 31.25 microseconds
    //PWM clock is half of system clock = 40 Mhz

    while (1)
    {

    }
}
