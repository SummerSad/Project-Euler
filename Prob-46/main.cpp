#include <stdio.h>
#include <math.h>

//What is the smallest odd composite that cannot be written
//as the sum of a prime and twice a square?

bool isPrime(int n)
{
	if(n < 2)
		return false;
	if(n == 2)
		return true;
	if(n % 2 == 0)
		return false;
	for(int i = 3; i * i <= n; i += 2)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

bool isSquare(int n)
{
	if(n < 0)
		return false;
	int root = (int)sqrt(n);
	return root * root == n;
}

bool isBach(int n)
{
	for(int i = 3; i < n; i += 2)
	{
		if(isPrime(i) && isSquare((n - i) / 2))
			return true;
	}
	return false;
}

int main()
{
	for(int i = 9; i < 10000; i += 2)
	{
		if(!isPrime(i) && !isBach(i))
			printf("%d ", i);
	}
	return 0;
}
