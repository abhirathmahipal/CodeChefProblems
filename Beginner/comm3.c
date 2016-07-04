#include <stdio.h>

int main (void)
{
	int cases, one[2], two[2], three[2], range, distance, pass = 0;
	scanf("%d", &cases);

	// all three receivers needn't be close to each other
	// if two are close to each other, it's enough

	for (int i = 0; i < cases; i++)
	{
		scanf("%d", &range);
		range = range * range;
		scanf(" %d %d", &one[0], &one[1]);
		scanf(" %d %d", &two[0], &two[1]);
		scanf(" %d %d", &three[0], &three[1]);

		distance = ((one[0] - two[0]) * (one[0] - two[0])) + ((one[1] - two[1]) * (one[1] - two[1]));
		if (distance <= range) pass++;
		distance = ((two[0] - three[0]) * (two[0] - three[0])) + ((two[1] - three[1]) * (two[1] - three[1]));
		if (distance <= range) pass++;
		distance = ((one[0] - three[0]) * (one[0] - three[0])) + ((one[1] - three[1]) * (one[1] - three[1]));
		if (distance <= range) pass++;

		if (pass > 1)
			printf("yes\n");
		else		
			printf("no\n");
		pass = 0;
	}

	return 0;
}