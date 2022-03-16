#include <stdio.h>

int main(int argc,char * argv[])
{
    enum Company{ GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT };
    enum Company a, b, c;
    a = XEROX;
    b = GOOGLE;
    c = EBAY;

    printf("%d\n%d\n%d\n",a, b, c);

    return 0;
}

