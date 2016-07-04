#include <stdio.h>

int main (void)
{
	int cases, price, quantity;
	double total;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		scanf("%d %d", &quantity, &price);
		if (quantity > 1000)
		{
			total = (price * quantity)* 0.9;
			printf("%lf\n", total);
		}
			
		else 
		{
			total = (price * quantity);
			printf("%lf\n", total);		

		}

	}

	return 0;
}