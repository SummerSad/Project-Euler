#include <stdio.h>

//Last ten digit

void priBackward(int *A, int size)
{
	for(int i = size - 1; i >= 0; i--)
	{
		printf("%d", A[i]);
	}
	printf("\n");
}

void digits(int *A, int size, int base, int n)
{
	for(int i = 0; i < n; i++)
	{
		int temp = 0;
		for(int j = 0; j < size; j++)
		{
			int d = A[j] * base + temp;
			A[j] = d % 10;
			temp = d / 10;
		}
	}
}

void plus(int *A, int *B, int size)
{
	int temp = 0;
	for(int i = 0; i < size; i++)
	{
		int d = A[i] + B[i] + temp;
		A[i] = d % 10;
		temp = d / 10;
	}
}

int main()
{
	int A[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int B[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int size = sizeof(A) / sizeof(A[0]);
	int MAX = 1000;
	for(int i = 1; i <= MAX; i++)
	{
		digits(B, size, i, i);
		plus(A, B, size);
		for(int j = 0; j < size; j++)
		{
			if(j == 0)
				B[j] = 1;
			else
				B[j] = 0;
		}
	}
	priBackward(A, size);
	return 0;
}
