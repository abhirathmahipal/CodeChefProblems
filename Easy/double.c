#include <stdio.h>

int main (void)
{
	int cases, test;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		scanf("%d", &test);
		// Maximum length is the same as the length of the palindrome in case
		// of an even count. Double strings can only be even.

		if (test % 2 == 1)
		{
			test--;
		}
		printf("%d\n", test);
	}

	return 0;
}