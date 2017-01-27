#include <stdio.h>
#define LIM 1001

int main(void)
{
	int i, sum, d, index;
	i = 1; sum = 1; d = 2;
	while (i < LIM*LIM)
	{
		for (index = 0; index < 4; ++index)
		{
			i += d;
			sum += i;
		}
		d += 2;
	}
	printf("%d\n", sum);
}