#include <stdio.h>

int main (void)
{
	int cases;
	char input;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		// Space before the format is essential.
		// Without the space it inputs newline or space as the value of input
		scanf(" %c", &input);

		if (input == 'b' || input == 'B')
			printf("BattleShip\n");
		else if (input == 'c' || input == 'C')
			printf("Cruiser\n");
		else if (input == 'd' || input == 'D')
			printf("Destroyer\n");
		else
			printf("Frigate\n");
	}

	return 0;
}