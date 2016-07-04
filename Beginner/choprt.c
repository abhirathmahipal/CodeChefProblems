#include <stdio.h>

int main () 
{
	int cases, right, left;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		scanf("%d %d", &left, &right);

		if (left > right)
			printf(">\n");
		else if (right > left)
			printf("<\n");
		else 
			printf("=\n");

	}

	return 0;
}
