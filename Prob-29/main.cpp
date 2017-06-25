#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Pow
{
	int a, b; // a^b
};

Pow strimDown(Pow X) // 4^6->2^12
{
	for(int i = 2; i * i <= X.a; i++)
	{
		if(X.a % i == 0)
		{
			int temp = X.a;
			int count = 0;
			while(temp % i == 0)
			{
				temp /= i;
				count++;
			}
			if(temp == 1)
			{
				return (Pow)
				{
					i, X.b * count
				};
			}
		}
	}
	return X;
}

bool isEqual(Pow X, Pow Y)
{

	if(strimDown(X).a == strimDown(Y).a && strimDown(X).b == strimDown(Y).b)
		return true;
	return false;
}

bool isAppear(Pow *arr, int size, Pow X)
{
	for(int i = 0; i < size; i++)
	{
		if(isEqual(arr[i], X))
			return true;
	}
	return false;
}

int countDistinct(int a_from, int a_to, int b_from, int b_to)
{
	Pow *arr = NULL;
	int size = 0;
	for(int i = a_from; i <= a_to; i++)
	{
		for(int j = b_from; j <= b_to; j++)
		{
			Pow X = {i, j};
			if(!isAppear(arr, size, X))
			{
				arr = (Pow *)realloc(arr, sizeof(Pow) * (size + 1));
				arr[size++] = X;
			}
		}
	}
	free(arr);
	arr = NULL;
	return size;
}

int main()
{
	printf("%d\n", countDistinct(2, 100, 2, 100));
	return 0;
}
