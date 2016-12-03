#include <stdio.h>
#include <math.h>

//Find the sum of all the primes below two million.

long long int is_prime(long long int n)
{
	long long int i;
	if (n == 1)
		return 0;
	for (i = 2; i <= sqrt((double)n); ++i)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}

int main(void)
{
	long long int n;
	long long int sum = 2;
	for (n = 3; n < 2000000; n += 2)
	{
		if (is_prime(n))
			sum += n;
	}
	printf("%lld\n", sum);
	return 0;
}