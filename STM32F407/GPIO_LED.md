# GPIO_LED

## 点灯

点亮板子上PE3，PE4和PG9的灯，保持常亮。

```c
#include "main.h"

int main(void)
{
    GPIO_InitTypeDef gpioinit;

    HAL_Init();

    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();

    gpioinit.Pin = GPIO_PIN_3;
    gpioinit.Mode = GPIO_MODE_OUTPUT_PP;
    gpioinit.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

    HAL_GPIO_Init(GPIOE, &gpioinit);

    gpioinit.Pin = GPIO_PIN_4;

    HAL_GPIO_Init(GPIOE, &gpioinit);

    gpioinit.Pin = GPIO_PIN_9;

    HAL_GPIO_Init(GPIOG, &gpioinit);

    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_RESET);

    while (1)
    {
        /* code */
    }
  
}
```

## 闪灯

让灯GE3每隔250毫秒闪一下。

```c
#include "main.h"

int main()
{
    GPIO_InitTypeDef gpioinit;

    HAL_Init();

    __HAL_RCC_GPIOE_CLK_ENABLE();

    gpioinit.Pin = GPIO_PIN_3;
    gpioinit.Mode = GPIO_MODE_OUTPUT_PP;
    gpioinit.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

    HAL_GPIO_Init(GPIOE, &gpioinit);

    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);

    while (1)
    {
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
        HAL_Delay(250);
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
        HAL_Delay(250);
    }
  
}
```
