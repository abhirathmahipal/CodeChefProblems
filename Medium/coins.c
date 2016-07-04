/* NOTE
 * Use long long instead of long or int. The answers are quite huge. Your solution won't be accepted if you use long or int
 */

#include <stdio.h>

/* History is used to store some results. It avoids recursive 
 * calls and greatly saves time.I came across this solution by 
 * browsing accepted source code. Without this it is not possible 
 * to perform the task within the time limit
*/
unsigned long long int history[1000000] = {0};



unsigned long long int calculate (unsigned long long int input);
int main (void)
{
	// They won't be inputting the number of test cases, therefore we have to 
	// go on as as there is input available. Hence the while loop instead of 
	// the for loop that we generally use.
	
	unsigned long long int input;
	while(scanf("%llu",&input) != EOF)
	{
		printf("%lld\n", calculate(input));

	}
	return 0;
}

unsigned long long int calculate(unsigned long long int input)
{
	unsigned long long int sum;
	// It is beneficial to convert all coins under 12 to dollars
	// This way we can save a little time as we don't have to divide
	if(input < 12)
		return input;

	if (input < 1000000 && history[input] != 0)
		return history[input];

	sum = calculate(input/2) + calculate(input/3) + calculate(input/4);
	if (input < 1000000)
		history[input] = sum;

	return sum;

}



