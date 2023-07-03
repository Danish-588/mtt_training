#include <stdint.h>
#include <tm4c123gh6pge.h>
#include <80mhz.h>

int i =0;

int main(void)
{
    System80Mhz();
    //clock
    SYSCTL_RCGCPWM_R |= 0x2;
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOG; //SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R6;

    for(i=0;i<1000;i++){}   //delay

    GPIO_PORTG_AFSEL_R |= 0X04;
    GPIO_PORTG_DEN_R |= 0X4;
    GPIO_PORTG_DIR_R |= 0X4;
    GPIO_PORTG_PCTL_R |= GPIO_PCTL_PG2_M1PWM0;


//    SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
//    SYSCTL_RCC_R &= (~0x000E0000);       // /2divider    clearing 3 bits for clock div



    //configuring for count down mode
    PWM1_0_CTL_R = 0; //clearing
    PWM1_0_GENA_R |= PWM_0_GENA_ACTCMPAD_ZERO|PWM_0_GENA_ACTLOAD_M;

    //generating
    PWM1_0_LOAD_R = 1249;       //31.25*40 = 1250-1 1249
    PWM1_0_CMPA_R = 625;        //for 50% duty cycle
    PWM1_0_CTL_R |= PWM_0_CTL_ENABLE;
    PWM1_ENABLE_R |= PWM_ENABLE_PWM0EN;        //enable outputs

    //for 32KHz frequency, time period = 31.25 microseconds
    //PWM clock is half of system clock = 40 Mhz

    while (1)
    {

    }
}
