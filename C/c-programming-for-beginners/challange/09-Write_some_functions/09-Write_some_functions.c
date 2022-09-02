/**
 * @file 09-Write_some_functions.c
 * @author Gabbi (gabbi.huang@outlook.com)
 * @date 2022-08-19
 * learning material: https://www.bilibili.com/video/BV19r4y127fu?spm_id_from=333.337.search-card.all.click
 *                    https://www.bilibili.com/video/BV1fq4y167rw?spm_id_from=333.337.search-card.all.click
 * 
 * gcd和squareRoot都是在afa的参与下完成的。
 * 
 * 函数gcd中的使A>B是afa帮我写的，函数套用函数是afa提了一嘴 可以这么用我便整上去了。
 * 本来这个笨脑袋是想用for循环实现的，也没真去写写看看可不可行，只是尝试了函数套用函数，既然可行就这样糊弄过去吧~
 * 
 * 函数squareRoot则是afa教我其中的while条件可以调用函数！啊！原来Jason表示能用到取绝对值的函数是在这里！
 */

#include <stdio.h>

/**
 * @brief To find the greatest common divisor of two nonnegative integer values and to return the result.
 * 
 * @param x an interger
 * @param y an interger
 * @return int the greatest common divisor of x and y
 */
int gcd(int x, int y)
{
    int A, B;// A > B
    if (x > y)
    {
        A = x;
        B = y;
    }else
    {
        A = y;
        B = x;
    }

    if (A % B == 0)
    {
        return B;
    }
    else
    {
        return gcd(B, A % B);
    }
}

/**
 * @brief To calculate the absolute value of a number
 * 
 * @param x 
 * @return float the absolute value of a number
 */
float absoluteValue(float x)
{
    if (x >= 0)
    {
        return x;
    }
    else
    {
        x = -x;
        return x;
    }
    
}

/**
 * @brief To compute the square root of a number
 * 
 * @param x 
 * @return float the square root of x 
 */
float squareRoot(int x)
{
    if (x < 0)
    {
        printf("Please enter an positive number.");
        return -1.0;
    }
    
    float g = x / 2.0f;

    while (absoluteValue(g * g - x) >= 0.00001)
    {
        g = (g + x / g) / 2;
    }
    
    return g;
}

/********************************************************************
 * 代码中第一大问题，我应该先把声明放在最前面，然后再开始写代码。（so that we can invoke it anywhere in the program）
 * gcd()
 * Jason的代码和我想法一样，我就是卡在赋值上，然后afa教我解决就是整一个tem出来，就可以重复循环了。
 * Jason没有判断大小，和台湾讲解公因式的视频一样
 * absoluteValue()
 * Jason的比较简单，学习
 * squareRoot()
 * Jason的代码没有两个return干净很多。
 ********************************************************************/