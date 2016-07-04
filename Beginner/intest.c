#include <stdio.h>

int main (void)
{
	int n, k, holder, counter = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &holder);
		if (holder % k == 0)
			counter++;
	}
	printf("%d\n", counter);

	return 0;

}
