#include <stdio.h>

// Longest Collatz sequence

long long int count_step(long long int n)
{
	long long int count = 0;
	long long int sth = n;
	while (sth > 1)
	{
		if (sth % 2 == 0)
			sth /= 2;
		else
			sth = sth * 3 + 1;
		++count;
	}
	return count;
}

int main(void)
{
	long long int n = 2;
	long long int max = 0;
	long long int result;
	while (n < 1000000)
	{
		if (count_step(n) > max)
		{
			max = count_step(n);
			result = n;
		}
		n += 1;
	}
	printf("%lld %lld\n", max, result);
	return 0;
}