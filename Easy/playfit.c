#include <stdio.h>

int main (void)
{
	int cases, temp, match, count, diff;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		scanf("%d", &count);
		// Declaring for initial values
		temp = 1000005, diff = 0;

		while (count--)
		{
			scanf("%d", &match);
			// Only replaces diff if new difference is more
			if (match - temp > diff)
				diff = match - temp;

			/* They do not need consecutive differences. 
			* say 1 2 4 7 9, Rooney can choose 1 and 9 and show a diff of 8
			* So temp has to be replaced with the lower value so that the highest 
			* diff can be seen
			*/
			
			if (temp > match)
				temp = match;
		}
		
			


		if (diff > 0)
			printf("%d\n", diff);
		else
			printf("UNFIT\n");
		


		diff = 0;
	}

	return 0;
}