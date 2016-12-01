#include <stdio.h>

//Even Fibonacci numbers
int fibo(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return fibo(n - 1) + fibo(n - 2);
}

int main(void)
{
	int i, sum;

	sum = 0;
	for (i = 1; fibo(i) <= 4000000; ++i)
	{
		if (fibo(i) % 2 == 0) // the even fibo
			sum += fibo(i);
	}
	printf("Sum = %d\n", sum);
	return 0;
}