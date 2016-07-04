#include <stdio.h>


int main (void)
{
	int cases, ability, days, missing;
	scanf("%d", &cases);
	char string[1000001];

	for (int i = 0; i < cases; i++)
	{
		// Resetting everything to zero for the next test case
		days = 0;
		missing = 0;
		ability = 0;
		scanf("%s", string);
		
		for(int i = 0; string[i] != '\0'; i++)
		{
			if(string[i] == '.')
			{
				while(string[i] == '.')
				{
					missing++;
					i++;
				}
				if (missing > ability)
				{
					ability = missing;
					days++;
				}
				missing = 0;
			}

		}

		printf("%d\n",days);

	}

	

	return 0;
}