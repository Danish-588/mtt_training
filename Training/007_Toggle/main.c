#include <tm4c123gh6pge.h>
#include <stdint.h>

volatile int old_data=0,i=0;

void delay(int a){
    for (i=0;i<a;i++){}
}

int main(void)
{
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R6;
    GPIO_PORTG_DIR_R  = 48;
    GPIO_PORTG_DEN_R  = 255;
    GPIO_PORTG_PUR_R  = 3;

    while(1)
    {
        old_data = GPIO_PORTG_DATA_R;       // stores the current data value to be compared with the new value
        delay(7000);                        // delay to debounce
        GPIO_PORTG_DATA_R = GPIO_PORTG_DATA_R ^ ((GPIO_PORTG_DATA_R & (~old_data)) << 4);  //(GPIO_PORTG_DATA_R & (~old_data) displays bits switching from 1 to 0
    }

}
