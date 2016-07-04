#include <stdio.h>

int main (void)
{
	int cases, size, range[10001], value[101], frequent = 0, occurance = 0;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		// Setting all counters to zero
		for (int j = 0; j < 10001; j++)
		{
			range[j] = 0;
		}

		scanf("%d", &size);
		size++;
		for (int j = 1; j < size; j++)
		{
			scanf("%d", &value[j]);
		}

		for (int j = 1; j < size; j++)
		{
			
			range[value[j]]++;
		}

		// Iterates and gets the largest value

		for (int j = 0; j < 10001; j++)
		{
			if (range[j] > occurance)
			{
				occurance = range[j];
				frequent = j;
			}

		}

		printf("%d %d\n", frequent, occurance);
		frequent = 0; occurance = 0;

	}

	return 0;
}