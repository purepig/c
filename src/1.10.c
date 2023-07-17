#include <stdio.h>

int main()
{
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c == '\\' || c == '\t' || c == '\b')
		{
			putchar('\\');
			if (c == '\\')
				putchar('\\');
			if (c == '\t')
				putchar('t');
			if (c == '\b')
				putchar('b');

		}


		else
			putchar(c);
	}
	return 0;
}
