// This question wants you to find out the minimum number of squares
// of equal dimension.
#include <stdio.h>

int main ()
{

	int cases, l, b, ll, bb;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		scanf("%d %d", &l, &b);
		ll = l;
		bb = b;
		// Finding HCF. Found this piece of code on programiz.com
		while (l != b)
    	{
	        if (l > b)
	        	l -= b;
	        else
	            b -= l;
    	}

		printf("%d\n", (ll/l * bb/b));
	}

	return 0;
}