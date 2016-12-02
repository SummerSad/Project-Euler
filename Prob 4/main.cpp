#include <stdio.h>

//Find the largest palindrome made from the product of two 3-digit numbers.

int palindrome(int n)
{
	int tam = n;
	int n_new = 0;
	while (tam > 0)
	{
		n_new = n_new * 10 + tam % 10;
		tam /= 10;
	}
	if (n == n_new)
		return 1;
	return 0;
}

int main(void)
{
	int i, j, max;
	max = 0;

	for (i = 999; i > 99; --i)
	{
		for (j = 999; j > 99; --j)
		{
			if (palindrome(i*j))
			{
				if (i*j > max)
					max = i*j;
			}
		}
	}

	printf("%d\n", max);

	return 0;
}