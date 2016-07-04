#include <stdio.h>

int main (void)
{
	int cases, m, x, y, product, counter = 0, houses[101];
	// I'm going to use actual numbers for simplicity instead of n - 1
	houses[0] = 0;
	scanf("%d", &cases);
	

	for (int i = 0; i < cases; i++)
	{
		scanf("%d %d %d", &m, &x, &y);
		int cophouse[m], lower[m], upper[m];

		// making houses safe
		for (int j = 1; j < 101; j++)
			houses[j] = 1;

		// Getting and storing the cop houses in an array
		for (int j = 0; j < m; j++)
			scanf("%d", &cophouse[j]);

		product = x * y;

		// To find the limit of safe houses
		for (int j = 0, diff = 0, sum = 0; j < m; j++)
		{
			diff = cophouse[j] - product;
			sum = cophouse[j] + product;

			if (diff < 0)
				diff = 0;
			if (sum > 100)
				sum = 100;
			lower[j] = diff;
			
			upper[j] = sum;
		

		}

		// Marking houses within the range as unsafe
		for (int j = 0; j < m; j++)
		{
			for (int k = lower[j]; k <= upper[j]; k++)
			{
				houses[k] = 0;
			}
		}


		// counting safe houses
		for (int j = 1; j < 101; j++)
		{
			if (houses[j] == 1)
				counter++;
		}

		printf("%d\n", counter);
		counter = 0;
	}

	return 0;
}