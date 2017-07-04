#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//What is the largest n-digit pandigital prime that exists?

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

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permu_solve(char *a, int l, int r)
{
	int i;
	if(l == r)
	{
		int temp = atoi(a);
		if(isPrime(temp) && temp > 7650000)
		{
			printf("%d ", temp);
		}
	}
	else
	{
		for(i = l; i <= r; i++)
		{
			swap((a + l), (a + i));
			permu_solve(a, l + 1, r);
			swap((a + l), (a + i)); //backtrack
		}
	}
}

int main()
{
	char str[] = "1234567";
	int len = strlen(str);
	permu_solve(str, 0, len - 1);
	return 0;
}
