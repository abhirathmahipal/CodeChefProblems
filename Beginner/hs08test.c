#include <stdio.h>

int main (void)
{
	float bal;
	int withdraw;
	scanf("%d %f", &withdraw, &bal);

	if (withdraw % 5 == 0 && bal - withdraw >= 0.50)
	{
		bal = bal - withdraw - 0.50;
		printf("%.2f\n", bal);
	}
	else
		printf("%.2f\n", bal);

	return 0;

}