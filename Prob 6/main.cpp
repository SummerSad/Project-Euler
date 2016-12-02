#include <stdio.h>

//Find the difference between the "sum of the squares" of the first one hundred natural numbers and the "square of the sum".

long int sum_of_squares(int n) // sum of squares
{
	long int s = 0;
	for (int i = 0; i < n; ++i)
		s += (i + 1)*(i + 1);
	return s;
}

long int square_of_sum(int n) // square of sum
{
	long int s = 0;
	for (int i = 0; i < n; ++i)
		s += i + 1;
	return s*s;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	printf("Result: %ld\n", square_of_sum(n) - sum_of_squares(n));
}