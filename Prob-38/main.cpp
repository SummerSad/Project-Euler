#include <stdio.h>
//9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645
//which is the concatenated product of 9 and (1,2,3,4,5).
//What is the largest 1 to 9 pandigital 9-digit number
//that can be formed as the concatenated product of an integer with (1,2, ... , n)

void print(int *A, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
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

int pow10(int n)
{
	int temp = 1;
	for(int i = 0; i < n; i++)
	{
		temp *= 10;
	}
	return temp;
}

bool isPandigital(int n)
{
	int arr[10] = {0}; // store 0 1 .. 9
	while(n > 0)
	{
		arr[n % 10]++;
		n /= 10;
	}
	for(int i = 0; i < 10; i++)
	{
		if(i == 0)
		{
			if(arr[i] != 0)
				return false;
		}
		else
		{
			if(arr[i] != 1)
				return false;
		}
	}
	return true;
}

void solve()
{
	// if i >= 10000
	// concatenated i with (1,2..) > 9 digit
	int max = 0;
	for(int i = 1; i <= 9999; i++)
	{
		int temp = 0;
		for(int j = 1; j <= 9; j++)
		{
			temp = temp * pow10(digit(i * j)) + i * j;
			if(isPandigital(temp))
			{
				if(temp > max)
				{
					max = temp;
				}
				break;
			}
		}
	}
	printf("%d\n", max);
}

int main()
{
	solve();
	return 0;
}
