#include <stdio.h>

int main (void)
{
	int cases, volume, coins, temp;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		
		scanf("%d %d", &coins, &volume);
		volume++;

		temp = 0;

		// Not the most efficient solution as various coniditions can be mentioned
		// to reduce the number of iterations using simple math, but this solution
		// is fast enough for the particular problem.
		for (int i = 1; i < volume; i++)
		{
			if (coins % i > temp)
				temp = coins % i;
		}

		printf("%d\n", temp);

	}

	return 0;
}