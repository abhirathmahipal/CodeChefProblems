#include <stdio.h>

int main (void)
{
	int a = 0, b = 0, c = 0;
	scanf("%d%d", &a,&b);
	c = a - b;

	// Note. The judge doesn't take zero as an answer. 
	// so if a = 2 and b = 1, the output '0' is wrong
	
	if (c % 10 == 9)
		printf("%d\n", c - 1);
	else
		printf("%d\n", c + 1);

	return 0;

}