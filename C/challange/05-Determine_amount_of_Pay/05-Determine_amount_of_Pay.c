/**
 * @file 05-Determine_amount_of_Pay.c
 * @author Gabbi
 * @date 2022-08-12
 */

#include <stdio.h>

int main()
{
    int workhours;
    int grossPay;
    float taxes;
    float netPay;

    printf("Please enter the number of hours you worked in a week:");
    scanf("%d", &workhours);

    if (workhours <= 40)
    {
        grossPay = workhours * 12;
    }
    else
    {
        grossPay = 40 * 12 + (workhours - 40) * 18;
    }

    if (grossPay <= 300)
    {
        taxes = 0.15 * grossPay;
    }
    else if (grossPay > 300 && grossPay <= 450) //我原本的写法是300 < grossPay <= 450 大错误！！！
    {
        taxes = 0.15 * 300 + 0.2 * (grossPay - 300);
    }
    else
    {
        taxes = 0.15 * 300 + 0.2 * 150 + 0.25 * (grossPay - 450);
    }

    netPay = grossPay - taxes;

    printf("You worked %d hours a week.\n", workhours);
    printf("The gross pay is %d.\n", grossPay);
    printf("The taxes are %f.\n", taxes);
    printf("The net pay is %f.\n", netPay);

    return 0;
}

/******************************************
******************反思*********************
在preproccessor那里要标注好constant
没有打注释 每一小段代码都可以标明自己做了什么，比如计算总收入，计算税收等
00 < grossPay <= 450大错误！！！没有这种写法，正确的应该是grossPay > 300 && grossPay <= 450
******************************************/