#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1406357289
//d1d2d3d4d5d6d7d8d9d10
//d2d3d4=406 is divisible by 2
//d3d4d5=063 is divisible by 3
//d4d5d6=635 is divisible by 5
//d5d6d7=357 is divisible by 7
//d6d7d8=572 is divisible by 11
//d7d8d9=728 is divisible by 13
//d8d9d10=289 is divisible by 17
bool isSubDiv(long long n)
{
	//d2d3d4
	long long d2d3d4 = (n / 1000000) % 1000;
	if(d2d3d4 % 2 != 0)
		return false;
	//d3d4d5
	long long d3d4d5 = (n / 100000) % 1000;
	if(d3d4d5 % 3 != 0)
		return false;
	//d4d5d6
	long long d4d5d6 = (n / 10000) % 1000;
	if(d4d5d6 % 5 != 0)
		return false;
	//d5d6d7
	long long d5d6d7 = (n / 1000) % 1000;
	if(d5d6d7 % 7 != 0)
		return false;
	//d6d7d8
	long long d6d7d8 = (n / 100) % 1000;
	if(d6d7d8 % 11 != 0)
		return false;
	//d7d8d9
	long long d7d8d9 = (n / 10) % 1000;
	if(d7d8d9 % 13 != 0)
		return false;
	//d8d9d10
	long long d8d9d10 = n % 1000;
	if(d8d9d10 % 17 != 0)
		return false;
	return true;
}

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

long long l_atoi(char *str)
{
	long long temp = 0;
	while(*str)
	{
		if(*str >= '0' && *str <= '9')
			temp = temp * 10 + *str - '0';
		str++;
	}
	return temp;
}

void permu_solve(char *a, int l, int r, long long &sum)
{
	int i;
	if(l == r)
	{
		long long temp = l_atoi(a);
		if(isSubDiv(temp))
		{
			printf("%lld\n", temp);
			sum += temp;
		}
	}
	else
	{
		for(i = l; i <= r; i++)
		{
			swap((a + l), (a + i));
			permu_solve(a, l + 1, r, sum);
			swap((a + l), (a + i)); //backtrack
		}
	}
}

int main()
{
	char str[] = "1023456789";
	int size = strlen(str);
	long long sum = 0;
	permu_solve(str, 0, size - 1, sum);
	printf("Sum = %lld\n", sum);
	return 0;
}
