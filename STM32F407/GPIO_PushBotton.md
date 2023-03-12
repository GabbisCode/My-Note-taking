GPIO_PushBotton

功能：每按下一一次按键，换一个灯闪烁。将翻转灯这个行为封装成一个小小的function。

```c
#include "main.h"

void LedToggle(int num);

int main(void)
{
    GPIO_InitTypeDef gpioinit;
    uint8_t pbState = 0, pbNewState = 0; // 0 button released; 1 button pressed;
    uint8_t ledIdx = 0;                  // index

    HAL_Init();
    gpioinit.Pin = GPIO_PIN_3 | GPIO_PIN_4;
    gpioinit.Mode = GPIO_MODE_OUTPUT_PP;
    gpioinit.Speed = GPIO_SPEED_FREQ_HIGH;
    __HAL_RCC_GPIOE_CLK_ENABLE();
    HAL_GPIO_Init(GPIOE, &gpioinit);

    gpioinit.Pin = GPIO_PIN_9;
    __HAL_RCC_GPIOG_CLK_ENABLE();
    HAL_GPIO_Init(GPIOG, &gpioinit);

    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 | GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_RESET);

    // initialize io port for the push botton
    __HAL_RCC_GPIOF_CLK_ENABLE();
    gpioinit.Pin = GPIO_PIN_8;
    gpioinit.Mode = GPIO_MODE_INPUT;
    gpioinit.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOF, &gpioinit);

    while (1)
    {
        pbNewState = (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_8) == GPIO_PIN_RESET) ? 1 : 0; // to make sure the botton is pressed

        if (pbState != pbNewState)
        {
            if (pbNewState == 1) // button pressed
            {
                // button pushed handler
                ledIdx = (ledIdx + 1) % 3; // move to a new led
            }
        }
        pbState = pbNewState;

        // execute the function LedToggle once per 500ms
        if (HAL_GetTick() % 500 == 0)
        {
            LedToggle(ledIdx);
        }

        // to ensure that it won't toggle the same led over and over again
        HAL_Delay(1);
    }
}

void LedToggle(int num)
{
    switch (num)
    {
    case 0:
        HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_3);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_SET);
        break;
    case 1:
        HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_SET);
        break;
    case 2:
        HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_9);
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 | GPIO_PIN_4, GPIO_PIN_SET);
        break;
    default:
        break;
    }
}


```
