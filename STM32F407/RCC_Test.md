学习使用时钟

```c
#include "main.h"

void System_Clock(void);

int main(void)
{
  GPIO_InitTypeDef gpioinit;
  uint32_t n;

  HAL_Init();

  // System_Clock();

  __HAL_RCC_GPIOE_CLK_ENABLE();
  gpioinit.Pin = GPIO_PIN_3;
  gpioinit.Mode = GPIO_MODE_OUTPUT_PP;
  gpioinit.Speed = GPIO_SPEED_FREQ_LOW;

  HAL_GPIO_Init(GPIOE, &gpioinit);

  while (1)
  {
    //  HAL_Delay(1000);
    n = 1000000;
    do
    {
      __NOP();
    } while (n--);
  
    HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_3);
  }
}

void System_Clock(void)
{
  RCC_OscInitTypeDef oscinit;
  RCC_ClkInitTypeDef clkinit;

  // HAL_RCC_OscConfig();
  oscinit.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  oscinit.HSEState = RCC_HSE_ON;
  oscinit.PLL.PLLState = RCC_PLL_ON;
  oscinit.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  oscinit.PLL.PLLM = 9;
  HAL_RCC_OscConfig(&oscinit);

  // HAL_RCC_ClockConfig();
  clkinit.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK;
  clkinit.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  clkinit.AHBCLKDivider = RCC_SYSCLK_DIV1;
  HAL_RCC_ClockConfig(&clkinit, FLASH_LATENCY_2);
}

```
