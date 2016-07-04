#include <stdio.h>

int main (void)
{
	int cases, hardness, tensile;
	float carbon;
	scanf("%d", &cases);

	//Pretty straight forward
	for (int i = 0; i < cases; i++)
	{
		scanf("%d %f %d", &hardness, &carbon, &tensile);
		if (hardness > 50 && carbon < 0.7 && tensile > 5600)
			printf("10\n");
		else if (hardness > 50 && carbon < 0.7 && tensile <= 5600)
			printf("9\n");
		else if (hardness <= 50 && carbon < 0.7 && tensile > 5600)
			printf("8\n");
		else if (hardness > 50 && carbon >= 0.7 && tensile > 5600)
			printf("7\n");
		else if (hardness > 50 || carbon < 0.7 || tensile > 5600)
			printf("6\n");
		else
			printf("5\n");

	}

	return 0;
}