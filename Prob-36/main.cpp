#include <stdio.h>
//The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
//Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

// d is base
bool isPal_d(int n, int d)
{
	int temp_1 = n;
	int temp_2 = 0;
	while(temp_1 > 0)
	{
		temp_2 = temp_2 * d + temp_1 % d;
		temp_1 /= d;
	}
	if(temp_2 == n)
		return true;
	return false;
}

int main()
{
	int count = 0;
	for(int i = 1; i < 1000000; i++)
	{
		if(isPal_d(i, 2) && isPal_d(i, 10))
		{
			printf("%d\n", i);
			count += i;
		}
	}
	printf("count: %d\n", count);
	return 0;
}
