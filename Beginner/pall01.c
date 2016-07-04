#include <stdio.h>

int main (void)
{
	int cases, input, reverse = 0, temp;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		scanf("%d", &input);
		int holder = input;
		reverse = 0;
		while (input)
		{
			temp = input % 10;
			reverse = (10 * reverse) + temp;
			input /= 10;
		}

		if (holder == reverse)
			printf("wins\n");
		else 
			printf("losses\n");

	}

	return 0;
}