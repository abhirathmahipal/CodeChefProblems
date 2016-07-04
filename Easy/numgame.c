#include <stdio.h>

int main (void)
{
	int cases, test;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		scanf("%d", &test);

		// Since the number of turns that can be played is equal to input - 1
		test--;
		if (test % 2 == 0)
			printf("BOB\n");
		else
			printf("ALICE\n");


	}


	return 0;
}