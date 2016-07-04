#include <stdio.h>
#include <string.h>
int main (void)
{
	// Number of cases
	int test = 0;
	scanf("%d", &test);
	int resultarray[test];
	
	// Storings each word in an array
	char teststring[100];
	int n = 0;
	for (int i = 0; i < test; i++)
	{
		scanf("%s",teststring);
		n = strlen(teststring);
		resultarray[i] = 0;
		for (int j = 0; j < n; j++)
		{
			switch(teststring[j])
			{
				case 'B':
					resultarray[i]++;
 
				case 'A':
				case 'D':
				case 'O':
				case 'P':
				case 'Q':
				case 'R':
					resultarray[i]++;
			}
		
		}
	}
	
	// Printing result array
	for (int i = 0; i < test; i++)
	{
		printf("%d\n", resultarray[i]);
	}
 
 
}  