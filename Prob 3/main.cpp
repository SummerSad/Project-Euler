#include <stdio.h>
#include <math.h>

//What is the largest prime factor of the number 600851475143 ?

long int is_prime(long int n)
{
	long int i;
	if (n == 1)
		return 0;
	for (i = 2; i < n / 2 + 1; ++i)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}

long int largest_p_factor(long int n)
{
	long int i;
	for (i = n; i > 0; --i)
	{
		if (is_prime(i) && n%i == 0)
			return i;
	}
	return 1;
}

int main(void)
{
	long int n;
	printf("Nhap n: ");
	scanf("%ld", &n);

	printf("%ld largest p factor: %ld\n", n, largest_p_factor(n));
	return 0;
}