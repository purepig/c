#include<stdio.h>
int main (void)
{   int fahr,celsius,lower,upper,step;
    lower=0,upper=300,step=20;
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = 5*(fahr-32)/9;  //除法注意5/9将舍去小数部分
        printf("%d\t%d\n",fahr,celsius);
        fahr=fahr + step;
    }
    
    printf("This is upper!\n");
    return 0;
}