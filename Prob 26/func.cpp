#include "func.h"

int re_cyc(int d)
{
	int d_d, val, cyc;
	// d_d is the d mirror
	d_d = d;
	while (d_d % 2 == 0)
		d_d /= 2;
	while (d_d % 5 == 0)
		d_d /= 5;
	if (d_d == 1)
		return 0;
	val = 10 % d_d; cyc = 1;
	while (val != 1)
	{
		val *= 10;
		val = val%d_d;
		++cyc;
	}
	return cyc;
}