#include <stdio.h>
int main (void)
{
	int test, input;
	scanf ("%d", &test);

	for (int i = 0; i < test; i++)
	{
		scanf("%d", &input);
		printf("%d\n", input/2 + 1);
	}

	return 0;
}