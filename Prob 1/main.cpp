#include <stdio.h>

//Find the sum of all the multiples of 3 or 5 below 1000.

int main(void)
{
	int s = 0;
	int i;
	for (i = 1; i < 1000; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0)
			s += i;
	}
	printf("Result: %d\n", s);
	return 0;
}