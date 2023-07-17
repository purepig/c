#include <stdio.h>
#define SPACE ' '

int main()
{
    int c;
    int nb = 0;
    while ((c = getchar()) != EOF) {

        
        ++nb;

        if (c != SPACE)
            nb = 0;

        if (nb < 2)
            putchar(c);
    }
    return 0;
}