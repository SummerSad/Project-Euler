#include <stdio.h>

// 1624: 1^5+6^5+2^5+4^5
int sum_fif(int n);

int main(void)
{
	int i, sum;
	for (sum = 0, i = 2; i <= 9999999; ++i)
		if (i == sum_fif(i))
			//printf("%d\n", i);
			sum += i;
	printf("%d\n", sum);
	return 0;
}

int sum_fif(int n)
{
	int i = n, sum = 0;
	while (i > 0)
	{
		sum += (i % 10)*(i % 10)*(i % 10)*(i % 10)*(i % 10);
		i /= 10;
	}
	return sum;
}