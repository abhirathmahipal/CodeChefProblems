#include <stdio.h>

int main (void)
{
	int cases, test = 0, counter = 0;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		scanf("%d", &test);

		/* Multiples of 5 add zeroes to the number
		 * 50 adds two zeros (2 makes it even, both the 5's add two zeroes)	
		 */

	
		 while (test/5 != 0)
		 {
		 	counter = counter + test/5;
		 	test/=5;
		 }

		printf("%d\n", counter);
		counter = 0;

	}

	return 0;
}