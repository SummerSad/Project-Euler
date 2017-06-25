#include <stdio.h>

// 145 = 1! + 4! + 5!

int Factorial(int n)
{
	int result = 1;
	for(int i = 2; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

bool isCurious(int n)
{
	int temp_n = n;
	int temp_factor = 0;
	while(temp_n > 0)
	{
		temp_factor += Factorial(temp_n % 10);
		temp_n /= 10;
	}
	if(temp_factor == n)
		return true;
	return false;
}

int main()
{
	int sum = 0;
	for(int i = 10; i < 100000; i++)
	{
		if(isCurious(i))
		{
			printf("%d\n", i);
			sum += i;
		}
	}
	printf("Sum: %d\n", sum);
	return 0;
}
