#include <stdio.h>
 
int isPrime(int num);
int isPalin(int num);
 
int main (void)
{
	int input;
	scanf("%d", &input);
	while(1)
	{
		
 
		// if it is prime, check for palindrome
		if (isPrime(input))
		{
			if (isPalin(input))
			{	
				printf("%d\n", input);		
				return 0;
			}
 
		}
 
		// Skipping all even numbers, we know they aren't prime
		if (input == 1)
			input++;
		else if (input % 2 == 0)
			input++;
		else
			input += 2;
		
	}
 
	return 0;
}
 
// Function Definitions
 
int isPrime (int num)
{
	if (num == 1)
		return 0;
	else
	{
		for (int i = 2; i * i <= num; i++)
		{
			if (num % i == 0)
				return 0;
		}
	}
	
	return 1;
}
 
int isPalin (int num)
{
	int temp = 0, inputcopy = num;
	while(num)
	{	
 
		temp = (temp * 10) + num % 10;
		num /= 10;
	}
 
	if (inputcopy == temp)
		return 1;
	else 
		return 0;
 
} 