#include <stdio.h>


// Found a better solution with a lower running time. 
// This is not efficient but well within bounds

int main (void)
{
	int cases, tmp, lwr, upr, j, counter = 0, reverse = 0, sum = 0;
	int digits [6];
	scanf("%d", &cases);
	

	for (int i = 0; i < cases; i++)
	{
		// getting the lower and upper bounds
		scanf("%d %d", &lwr, &upr);
		// increasing it so that i < upr can be used instead of i <= upr
		upr++; 

		for (int i = lwr; i < upr; i++)
		{
			tmp = i;
			j = 0;
			counter = 0;

			// Storing each digit in an array
			while (tmp)
			{
				digits[counter] = tmp % 10;
				counter++;
				tmp /= 10;
				
			}

			j = counter;

			// Multiplying each digit by powers of 10 to get the reverse
			for (int k = 0; k < j; k++, counter--)
			{
				for (int l = 1; l < counter; l++) 
				{
					digits[k] *= 10;
				}

				reverse = reverse + digits[k];
			}

			
			if (reverse == i)
				sum += reverse;

			reverse = 0;
		}
		printf("%d\n", sum);
		sum = 0;
	}

	return 0;
}