//Find the value of d < 1000 for which 1/d contains
//the longest recurring cycle in its decimal fraction part.
// 1/3=0.(3)

// the idea: val=10%d -> then check; ; val*=10; val=val%d ; check
// put in the loop
// if val==1 stop. because the next is 10 - 1 - 10 - 1...
#include "func.h"

int main(void)
{
	int numb[MAX] = { 0 };
	int i, max;
	for (i = 1; i < 1000; ++i)
		numb[i] = re_cyc(i);
	for (max = 0, i = 1; i < 1000; ++i)
		if (numb[i]>numb[max])
			max = i;
	printf("%d\n", max);
	return 0;
}

// another idea
// 1/3=3/9-0.(3)
// 1/11=9/99=0.(09)
// the smallest number of 9 which d | 99..99
// is the recurring cycle of d