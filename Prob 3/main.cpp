#include <stdio.h>
#include <math.h>

//What is the largest prime factor of the number 600851475143 ?

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

long long int largest_p_factor(long long int n) // excpet when n is a prime
{
	long long int i;
	long long tam = n;
	while (tam % 2 == 0 && tam > 2)
		tam /= 2;

	for (i = floor(sqrt((double(tam)))) + 1; i > 0; i -= 2) // run from sqrt(n) //because n is not a prime
	{
		if (is_prime(i) && tam%i == 0)
			return i;
	}
	return 1;
}

int main(void)
{
	long long int n;

	printf("Nhap n: ");
	scanf("%lld", &n);
	
	printf("%lld largest p factor: %lld\n", n, largest_p_factor(n));
	return 0;
}