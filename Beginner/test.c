#include <stdio.h>

int main (void)
{
	int test;
	scanf("%d",  &test);
	while (test != 42)
	{
		printf("%d\n", test);
		scanf("%d", &test);
	}

	return 0;
}
