#include<stdio.h>
int main (void)
{   int fahr,celsius,lower,upper,step;
    lower=-100,upper=100,step=20;
    celsius = lower;
    while (celsius <= upper)
    {
        fahr = celsius *9 /5 + 32;
        printf("%d\t%d\n",celsius,fahr);
        celsius=celsius + step;
    }
    
    printf("This is upper!\n");
    return 0;
}