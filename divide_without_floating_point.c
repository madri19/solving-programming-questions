// Given 2 ints a, b, provide a function that returns a/b roundest to the nearest whole number without floating point (5/2 -> 3)
#include <stdio.h>

int divide(int a, int b);

int main()
{
    int x = divide(5,2);
    printf("%d\n", x);
    x = divide(7,3);
    printf("%d\n", x);
    x = divide(5,2);
    printf("%d\n", x);
    x = divide(1,3);
    printf("%d\n", x);
}

int divide( int a, int b)
{
    int q = a / b;
    int r = a % b;
    
    if((2*r/b) >= 1)
        return q + 1;
    else
        return q;
}
