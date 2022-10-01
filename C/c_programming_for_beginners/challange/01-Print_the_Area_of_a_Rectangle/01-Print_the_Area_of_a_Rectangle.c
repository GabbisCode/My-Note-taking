#include <stdio.h>

int main(int argc,char * argv[])
{
    double widthOfRect = 5.23;
    double heightOfRect = 4.11;
    double perimeterOfRect = 0.0;
    double areaOfRect = 0.0;

    perimeterOfRect = 2.0*(widthOfRect + heightOfRect);
    areaOfRect = widthOfRect * heightOfRect;

    printf("The perimeter of the rectangle is: %f\n", perimeterOfRect);
    printf("The area of the rectangle is:%f", areaOfRect);

    return 0;

}
