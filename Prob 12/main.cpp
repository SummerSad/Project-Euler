#include <stdio.h>
#include <math.h>

// What is the value of the first triangle number to have over five hundred divisors?

// idea: 12 = 2^2 x 3^1
// num of divisor: (2+1) x (1+1)

// gcd(n,n+1)=1
long int triangle_num(int n) // the num th triangle number
{
	return n*(n + 1) / 2;
}

int is_prime(long int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt((double)n); ++i)
		if (n%i == 0)
			return 0;
	return 1;
}

int num_of_divisor(long int n)
{
	int result = 1;
	int t;
	long int i, sth;
	sth = n;
	while (sth % 2 == 0) 
	{
		++result;
		sth /= 2;		// "even" no more
	}
	for (i = 3; i <= sth; i += 2) // start from p = 3
		if (is_prime(i))
		{
			t = 1;
			while (sth%i == 0)
			{
				++t;
				sth /= i;
			}
			result *= t;
		}
	return result;
}

int num_divisor_of_triangle(long int n)
{
	if (n % 2 == 0)
	{
		return num_of_divisor(n / 2)*(num_of_divisor(n + 1));
	}
	else
		return num_of_divisor(n)*(num_of_divisor((n + 1) / 2));
}


int main(void)
{
	long int n = 1;
	while (num_divisor_of_triangle(n) <= 500)
		n++;
	printf("%ld\n", n);
	
	return 0;
}