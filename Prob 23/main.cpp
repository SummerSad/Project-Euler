// Find the sum of all the positive integers which cannot
// be written as the sum of two abundant numbers.
// Any number >= 21823 is plus of 2 abundant numbers
#include "func.h"

int main(void)
{
	// 1 stand for abundant number
	// 0 is not
	int abu[7000];
	int len, i, j, sum;
	long long int sum_abu;
	// build a list full of abundant numbers
	for (len = 0, i = 12; i < 28124; ++i)
		if (is_abundant(i))
			abu[len++] = i;
	// build a list for plus 2 abundant numbers
	int plus_abu[28124] = { 0 };
	for (i = 0; i < len; ++i)
		for (j = i; j < len; ++j)
			if (abu[i] + abu[j] < 28124)
				// 1 stand for plus of 2 abundant numbers
				// 0 is not
				plus_abu[abu[i] + abu[j]] = 1;
	for (sum = 0, i = 0; i < 28124; ++i)
		if (plus_abu[i] == 0)
			// not plus of 2 abundant numbers
			sum += i;
	printf("%d\n", sum);
}