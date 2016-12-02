#include <stdio.h>
#include <math.h>

//What is the 10 001st prime number?

int is_prime(long long int n)
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
	int count = 1;
	long long int n = 3;
	int sth;
	scanf("%d", &sth);
	for (; count < sth; n += 2) // end when count == sth
	{
		if (is_prime(n))
			++count;
	}
	printf("%lld\n", n-2);
	return 0;
}
