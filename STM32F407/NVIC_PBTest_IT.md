通过使用按键exti中断来控制灯的闪烁

```c
#include "main.h"

uint8_t gLEDIdx = 0; //  global 0 1 2

//  only for practice's sake
void SystemClock_Config(void);

void toggleLED(int LEDIdx);

int main(void)
{
    GPIO_InitTypeDef gpioinit;

    HAL_Init();
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);
    SystemClock_Config();

    //  Initialize GPIO pins for LEDs
    gpioinit.Pin = GPIO_PIN_3 | GPIO_PIN_4;
    gpioinit.Mode = GPIO_MODE_OUTPUT_PP;
    gpioinit.Speed = GPIO_SPEED_FREQ_LOW;
    __HAL_RCC_GPIOE_CLK_ENABLE();
    HAL_GPIO_Init(GPIOE, &gpioinit);
    gpioinit.Pin = GPIO_PIN_9;
    __HAL_RCC_GPIOG_CLK_ENABLE();
    HAL_GPIO_Init(GPIOG, &gpioinit);

    //  Initialize GPIO pin for push botton
    gpioinit.Pin = GPIO_PIN_9;
    gpioinit.Mode = GPIO_MODE_IT_RISING; //  mode: input
    gpioinit.Pull = GPIO_NOPULL;
    __HAL_RCC_GPIOA_CLK_ENABLE();
    HAL_GPIO_Init(GPIOF, &gpioinit);

    //  set exti priority
    HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);

    //  enable IRQ
    HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

    while (1)
    {
        toggleLED(gLEDIdx);
        HAL_Delay(200);
    }
}

//
void EXTI9_5_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    gLEDIdx = (gLEDIdx + 1) % 3;
}

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef oscinit;
    RCC_ClkInitTypeDef clkinit;

    oscinit.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    oscinit.HSEState = RCC_HSE_ON;
    oscinit.PLL.PLLState = RCC_PLL_ON;
    oscinit.PLL.PLLSource = RCC_PLLSOURCE_HSE; // 8M Hz
    oscinit.PLL.PLLM = 9;                      // 8 MHz * 9 = 72MHz
    HAL_RCC_OscConfig(&oscinit);

    clkinit.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    clkinit.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    clkinit.AHBCLKDivider = RCC_SYSCLK_DIV1;
    clkinit.APB1CLKDivider = RCC_HCLK_DIV2;
    clkinit.APB2CLKDivider = RCC_HCLK_DIV1;
    HAL_RCC_ClockConfig(&clkinit, FLASH_LATENCY_2);
}

void toggleLED(int LEDIdx)
{
    switch (LEDIdx)
    {
    case 0:
        HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_3);
        HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_SET);
        break;
    case 1:
        HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
        HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_SET);
        break;
    case 2:
        HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_9);
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 | GPIO_PIN_4, GPIO_PIN_SET);
        break;
    default:
        //  error handler 
        break;
    }
}


```
