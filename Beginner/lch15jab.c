#include <stdio.h>

int main ()
{

	int cases, counter [26], len, counteriterator;
	char array[51];

	scanf("%d", &cases);

	

	for (int i = 0; i < cases; i++)
	{
		scanf(" %s", array);

		// Setting all the ints to zero
		for (int i = 0; i < 26; i++)
		{
			counter[i] = 0;
		}

		// Finding length of the array
		len = 0;
		while(array[len] != '\0')
			len++;
		
		for (int j = 0, tmp = 0; array[j] != '\0'; j++)
		{
			tmp = array[j] - 97;
			counter[tmp]++;
		}

		

		for (counteriterator = 0; counteriterator < 26; counteriterator++)
		{
			if (counter[counteriterator] * 2 == len)
			{
				printf("YES\n");
				break;
			}
		}

		if (counteriterator == 26)
		{
			printf("NO\n");
		}


	}

	return 0;
}