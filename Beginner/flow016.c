#include <stdio.h>

int main (void)
{
	int cases, a, b, aa, bb;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		scanf("%d%d", &a, &b);

		aa = a;
		bb = b;

		while (a != b)
		{
			if(a > b)
				a -= b;
			else 
				b -= a;
		}

		// a and b are now equal to hcf
		aa = (aa * bb) / a;
		printf("%d %d\n",a, aa);


	}

	return 0;
}