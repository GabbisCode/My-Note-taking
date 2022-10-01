/**
 * Author: Gabbi
 * Date: 2022/3/20
 **/

#include <stdio.h>

int main()
{
    //display the byte size of int, char, long, long long, double, long double
    printf("The length of int is: %zd\n", sizeof(int));
    printf("The length of char is: %zd\n", sizeof(char)); 
    printf("The length of long is: %zd\n", sizeof(long)); 
    printf("The length of long long is: %zd\n", sizeof(long long)); 
    printf("The length of double is: %zd\n", sizeof(double)); 
    printf("The length of long double is: %zd\n", sizeof(long double));  

    return 0;
}