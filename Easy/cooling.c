#include <stdio.h>

int main (void)
{
	int cases, count, pie [100], racks[100], n;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		scanf("%d", &n);

		// Getting input 
		for (int j = 0; j < n; j++)
			scanf("%d", &pie[j]);

		for (int j = 0; j < n; j++)
			scanf("%d", &racks[j]);

		// Sorting rack capacity array using bubble sort
		
		for (int j = 1, m = n - 1; j < n; j++, m--)
		{
			for (int k = 0, temp = 0; k < m; k++)
			{
				// For sorring rack capacity
				if (racks[k] > racks[k + 1])
				{
					temp = racks[k];
					racks[k] = racks[k + 1];
					racks[k + 1] = temp;
				}
			}
		}

		
		// Iterating array and finding how many can be held
		// Taking a given pie and placing it on the weakest possible rack
		count = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (racks[k] >= pie[j])
				{
					count++;
					racks[k] = 0;
					break;
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}				