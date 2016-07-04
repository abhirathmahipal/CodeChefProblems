#include <stdio.h>
void part(int *, int, int);
void merge(int *, int, int, int);

int main () 
{
	int numbers;

	scanf("%d", &numbers);

	int array[numbers];
	// Getting input
	for (int i = 0; i < numbers; i++)
		scanf("%d", &array[i]);
	
	int *pointer = array;
	// Using merge sort to sort the numbers
	part(pointer, 0, numbers - 1);
	
	// Printing numbers
	for (int i = 0; i < numbers; i++)
		printf("%d\n", array[i]);

	return 0;
}

void part(int *pointer, int start, int end)
{
	// Using recursion to split the input into halves
	if (start < end)
	{
		int m = (start + end)/2;
		part(pointer, start, m);
		part(pointer, m+1, end);
		merge(pointer, start, m, end);
	}


}


void merge(int *pointer, int start, int m, int end)
{

	// using bubble sort in case there are only two only
	// elements to sort. It is faster than merging.
	if (end - start + 1 == 2)
	{
		if (*(pointer + start) > *(pointer + start + 1))
		{
			int temp = *(pointer + start);
			*(pointer + start) = *(pointer + start + 1);
			*(pointer + start + 1) = temp;
		}
	}
	else
	{


		int leftsize = m - start + 1;
		int rightsize = end - m;

		int leftarray[leftsize], rightarray[rightsize];

		for (int i = 0; i < leftsize; i++)
			leftarray[i] = *(pointer + start + i);

		for (int i = 0, j = m + 1; i < rightsize; i++)
			rightarray[i] = *(pointer + j + i);

		int leftiterate = 0, rightiterate = 0, originaliterate = start;

		while(leftiterate < leftsize && rightiterate < rightsize)
		{
			if (leftarray[leftiterate] < rightarray[rightiterate])
			{
				*(pointer + originaliterate) = leftarray[leftiterate];
				leftiterate++;
				originaliterate++;
			}
			else
			{
				*(pointer + originaliterate) = rightarray[rightiterate];
				rightiterate++;
				originaliterate++;
			}


		}

		while (leftiterate < leftsize)
		{
			*(pointer + originaliterate) = leftarray[leftiterate];
			leftiterate++;
			originaliterate++;
		}

		while (rightiterate < rightsize)
		{
			*(pointer + originaliterate) = rightarray[rightiterate];
			rightiterate++;
			originaliterate++;
		}

	}

}

