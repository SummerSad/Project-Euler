#include <stdio.h>
#include <stdlib.h>

void print_arr(int *A, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

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

// Erathos method to list prime number
void Eratos(int MAX, int *&result, int &size)
{
	int *era = new int[MAX];
	for(int i = 0; i < MAX; i++)
	{
		if(i == 0 || i == 1)
			era[i] = 0;
		else
			era[i] = 1;
	}
	result = NULL;
	size = 0;
	for(int i = 2; i < MAX; i++)
	{
		if(era[i] == 1)
		{
			result = (int *)realloc(result, sizeof(int) * (size + 1));
			result[size++] = i;
			for(int j = 2; j <= MAX / i; j++)
			{
				era[i * j] = 0;
			}
		}
	}
	delete[]era;
	era = NULL;
}

int power(int a, int n)
{
	if(a == 0 || a == 1)
		return a;
	int result = 1;
	for(int i = 0; i < n; i++)
	{
		result *= a;
	}
	return result;
}

int digit(int n)
{
	int temp = 0;
	while(n > 0)
	{
		temp++;
		n /= 10;
	}
	return temp;
}

int swap(int n)
{
	int first = n % 10;
	return n / 10 + first * power(10, digit(n) - 1);
	// 197 -> 719 -> 971
}

// p is prime
bool isPrimeCir(int p)
{
	int temp = p;
	do
	{
		temp = swap(temp);
		if(!isPrime(temp))
			return false;
	}
	while(temp != p);
	return true;
}

int countPrimeCir(int MAX)
{
	int *arr;
	int size;
	Eratos(MAX, arr, size);
	int count = 0;
	for(int i = 0; i < size; i++)
	{
		if(isPrimeCir(arr[i]))
			count++;
	}
	free(arr);
	arr = NULL;
	return count;
}

int main()
{
	printf("%d\n", countPrimeCir(1000000));
	return 0;
}
