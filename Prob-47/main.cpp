#include <stdio.h>

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

//14 = 2 × 7 have two distinct prime factors
bool isDistinct(int n, int count)
{
	int temp = 0;
	if(n % 2 == 0)
	{
		temp++;
		while(n % 2 == 0)
			n /= 2;
	}
	for(int i = 3; i <= n; i += 2)
	{
		if(n % i == 0 && isPrime(i))
		{
			temp++;
			n /= i;
		}
	}
	return temp == count;
}

int main()
{
	int MAX = 1000000;
	for(int i = 4; i <= MAX; i++)
	{
		if(isDistinct(i, 4) && isDistinct(i + 1, 4) && isDistinct(i + 2, 4) && isDistinct(i + 3, 4))
		{
			printf("%d %d %d %d\n", i, i + 1, i + 2, i + 3);
			break;
		}
	}
	return 0;
}
