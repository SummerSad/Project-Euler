#include <stdio.h>

// Find the sum of all products whose multiplicand/multiplier/product identity
// can be written as a 1 through 9 pandigital.
// 39 × 186 = 7254

void makeZero(int *A, int size)
{
	for(int i = 0; i < size; i++)
	{
		A[i] = 0;
	}
}

bool isFull(int *A, int size)
{
	if(A[0] != 0)
		return false;
	for(int i = 1; i < size; i++)
	{
		if(A[i] == 0 || A[i] > 1)
			return false;
	}
	return true;
}

void countDigit(int *A, int size, int n)
{
	while(n > 0)
	{
		A[n % 10]++;
		n = n / 10;
	}
}

bool isUnusual(int n)
{
	int digit[10];
	for(int i = 1; i * i <= n; i++)
	{
		makeZero(digit, 10);
		if(n % i == 0)
		{
			countDigit(digit, 10, i);
			countDigit(digit, 10, n / i);
			countDigit(digit, 10, n);
			if(isFull(digit, 10))
				return true;
		}
	}
	return false;
}

void printArr(int *A, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main()
{
	int sum = 0;
	for(int i = 0; i < 10000; i++)
	{
		if(isUnusual(i))
		{
			printf("%d\n", i);
			sum += i;
		}
	}
	printf("Sum: %d\n", sum);
	return 0;
}
