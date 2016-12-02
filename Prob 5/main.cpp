#include <stdio.h>

//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?
//least common multiple - lcm

int lcm(int a, int b)
{
	int i;
	for (i = 1; i <= b; ++i) // run i from 1 to b: lcm run from a to ab
	{
		if ((a*i) % b == 0)
			return a*i;
	}
}

int main(void)
{
	int i, result;
	result = 1;
	for (i = 2; i <= 20; ++i)
		result = lcm(result, i);

	printf("%d\n", result);
	return 0;
}

