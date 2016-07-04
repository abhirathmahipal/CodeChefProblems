#include <stdio.h>

int main (void)
{
	int particlecount, cap, chambercount;
	scanf("%d %d %d", &particlecount, &cap, &chambercount);

	int chamber[chambercount];

	for (int j = 0; j < chambercount; j++)
		chamber[j] = 0;

	// using mathematical calculations
	/* if a nuke has a capacity of 1, only if two particles are,
	 * bombarded, it moves to the next chamber. So particle/(cap+ 1)
	 * are sent to the second chamber and the remainder stays in 
	 * in the first chamber. 
	 * say 3 particles are bombarded, only one 
	 * remains in the first chamber (particle % (cap + 1)
	*/
	 	
	int count = cap + 1;
	int i = 0;
	while (particlecount > 0 && i < chambercount)
	{
		chamber[i] = particlecount % count;
		particlecount /= count;
		i++;
	}


	for(int j = 0; j < chambercount; j++)
		printf("%d ",chamber[j]);
	
	/*
	// Iterating each particle one by one. 
	// This is slow and it exceeds the time limit.
	int i = 0, count = chambercount - 1;
	while(particlecount--)
	{
		
		chamber[0]++;
		
		if (chamber[0] > cap)
		{
			while(chamber[i] > cap && i <= count)
			{
				chamber[i] = 0;
				if (i < count)
				{
					i++;
					chamber[i]++;
				}
			}

			i = 0;
		}

	}
	*/ 



	return 0;
}