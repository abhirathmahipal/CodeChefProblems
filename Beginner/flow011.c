#include <stdio.h>

int main (void)
{
	int cases, base;
	float temp;
	scanf("%d", &cases);

	// There seems to be a problem even though it gives the exact same output as 
	// required. I read the comments, many people think there's some fault with the problems
	for (int i = 0; i < cases; i++)
	{
		scanf("%d", &base);
		if (base < 1500)
		{
			base *= 2;
			printf("%d\n", base);
		}
		else
		{
			temp = 0.98 * base;
			base += 500;
			temp += base;
			printf("%.1f\n", temp);
		}

	}

	return 0;
}