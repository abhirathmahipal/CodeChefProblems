#include <string.h>
#include <stdio.h>
#include <stdbool.h>


int main(void)
{
	
	// Int for storing number of cases and length of input
	int cases = 0, length = 0, half = 0, halfforeven = 0, halfforodd = 0, remainder = 0, temp, temp2;
	scanf("%d", &cases);
	char number [1000001];
	bool incrementornot;

	// Getting input and changing it
	for (int i = 0; i < cases; i++)
	{
		scanf("%s", number);
		length = strlen(number);
		// Strlen returns actual length and since arrays start with 0
		half = length/2;
		halfforeven = half - 1;
		halfforodd = half;
		remainder = length % 2;
		// for single digit inputs
		if (length == 1)
		{
			if (number[0] == 57)
				printf("11\n");
			else 
			{
				number[0]++;
				printf("%c\n", number[0]);
			}

		}
		else 
		{

			// only make changes if the right half is larger than the left half reversed

			// This checks if we need to add one to the center most element or not. If the reverse of the
			// left half is larger than the right half we can simply copy it and make it a palindrome
			if (remainder == 0)
			{
				temp = halfforeven;
				temp2 = temp + 1;
			}
			else
			{
				temp = halfforodd - 1;
				temp2 = temp + 2;
			}

			incrementornot = true;

			for (;temp > -1; temp--, temp2++)
			{
				if (number[temp] > number[temp2])
				{
					incrementornot = false;
					break;
				}
				
				if (number[temp] < number[temp2])
				{
					break;
				}
			}

			if (incrementornot == true)
			{

				// For even number of digits
				if (remainder == 0)
				{

					// if the number is not 9
					if (number[halfforeven] != 57)
					{
						number[halfforeven]++;
					}
					// if the number is 9
					else 
					{
						// Keep going until you find a non nine number
						while (halfforeven > -1 && number[halfforeven] == 57)
						{
							number[halfforeven] = '0';
							halfforeven--;
						}
						if (halfforeven >= 0)
							number[halfforeven]++;
						
					}

				}

				// For odd number of digits
				else 
				{
									
						// If the number is a non nine number
						if (number[halfforodd] != 57)
						{
							number[halfforodd]++;

						}
						// if the number is 9
						else 
						{
							// Keep going until you find a non 9 number
							while(halfforodd > -1 && number[halfforodd] == 57)
							{
								number[halfforodd] = '0';
								halfforodd--;
							}
							if (halfforodd >= 0)
									number[halfforodd]++;

							
						}
					}
			}


			// changing the contents and copying the left half into the right half

			// for even number of digits
			if (remainder == 0)
			{
				for (int j = half - 1, halfcopy = j + 1; j > -1; j--, halfcopy++)
				{
					number[halfcopy] = number[j];
				}
			}
			// for odd number of digits
			else
			{
				for (int j = half - 1, halfcopy = half + 1; j > -1; j--, halfcopy++)
				{
					number[halfcopy] = number[j];
				}

			}

			// For numbers like 999, 9999 which have been turned into zeroes
			if (halfforodd == -1 || halfforeven == -1)
			{
				number[0] = '1';
				number[length] = '1';
				// number[length] was initially a null character. We replaced it with a '1'
				// so it doesn't know the end. Say the last palindrome has 20 digits, the null is at 21st, so
				// it prints up to the 21st character instead of the current length of the palindrome
				number[length + 1] = '\0';
			}	

			// Printing the altered arrays. Each in a new line

			printf("%s\n", number);
				
		}
	}

	return 0;
}
