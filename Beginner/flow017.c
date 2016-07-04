#include <stdio.h>

int main (void)
{
	int cases, a, b, c;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		scanf("%d%d%d", &a, &b, &c);

		// If a is the largest
		if (a > b && a > c)
		{
			if (b > c)
				printf("%d\n", b);
			else 
				printf("%d\n", c);
		}

		// If b is the largest
		else if (b > a && b > c)
		{
			if (a > c)
				printf("%d\n", a);
			else
				printf("%d\n", c);
		}
		// If C is the largest
		else 
		{
			if (b > a)
				printf("%d\n", b);
			else 
				printf("%d\n", a);
		}
			
	}

	return 0;
}