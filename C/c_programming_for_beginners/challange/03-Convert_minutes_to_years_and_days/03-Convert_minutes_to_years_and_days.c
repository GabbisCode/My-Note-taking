/**
 * Author: Gabbi
 * Date: 2022/3/19
**/

#include <stdio.h>

int main()
{
    int theNumOfMinutes = 0;
    printf("Please enter the number of minutes:");
    scanf("%d", &theNumOfMinutes);
    printf("You've entered: %d\n", theNumOfMinutes);

    double minutesInYear = 60 * 24 * 365;
    printf("There are %f minutes in Year.\n", minutesInYear);

    double Years = theNumOfMinutes / minutesInYear;
    printf("The equivalent years of the number of minutes are: %f.\n", Years);

    double Days = Years * 365;
    printf ("The equivalent days of the number of minutes are: %f.\n", Days);

    return 0;
}

/** Things I need to improve:
 *  put the declaration of variables all together from the beginning, instead of naming them here and there
 *  while naming the variables, there should be the lower case for the first word, and every word after that upper case the first character
 *  comments for functions
 *  use one output for the result: printf("%d minutes is approximately %f years and %f days\n", theNumOfMinutes, Years, Days);
*/