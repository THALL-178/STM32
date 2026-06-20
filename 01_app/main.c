#include "stm32f10x.h"
#include "bsp_led.h"
int main(void)
{
    LED_Init();
    LED_On();
    while (1);

    
}