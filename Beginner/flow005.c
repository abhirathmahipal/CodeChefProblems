#include <stdio.h>

int main (void)
{
	int cases, input, notecount, temp;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{	
		scanf("%d", &input);
		notecount = 0;

		// The same could have been implemented using a loop

		temp = input/100;
		notecount = notecount + temp;
		input = input - (100 * temp);

		temp = input/50;
		notecount = notecount + temp;
		input = input - (50 * temp);

		temp = input/10;
		notecount = notecount + temp;
		input = input - (10 * temp);

		temp = input/5;
		notecount = notecount + temp;
		input = input - (5 * temp);

		temp = input/2;
		notecount = notecount + temp;
		input = input - (2 * temp);

		temp = input/1;
		notecount = notecount + temp;
		

		printf("%d\n", notecount);

	}

	return 0;
}