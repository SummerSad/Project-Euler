#include <stdio.h>
// An irrational decimal fraction is created by concatenating the positive
// integers:
// 0.123456789101112131415161718192021...

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

int power_10(int n)
{
	int temp = 1;
	for(int i = 0; i < n; i++)
	{
		temp *= 10;
	}
	return temp;
}

int nth_digit(int nth)
{
	int i = 0;
	int count = 0;
	while(count < nth)
	{
		count += digit(++i);
	}
	int over = count - nth;
	return (i / power_10(over)) % 10;
}

int main()
{
	int result = 1;
	for(int i = 1; i <= 6; i++)
	{
		result *= nth_digit(power_10(i));
	}
	printf("%d\n", result);
	return 0;
}
