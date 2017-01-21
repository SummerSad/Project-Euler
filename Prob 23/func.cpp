#include "func.h"

int is_abundant(int n)
{
	int i, re;
	if (n < 12)
		return 0;
	for (re = 1, i = 2; i * i <= n; ++i)
	{
		if (n%i == 0 && i*i < n)
			re += i + n / i;
		if (i*i == n)
			re += i;
	}
	if (re > n)
		return 1;
	return 0;
}