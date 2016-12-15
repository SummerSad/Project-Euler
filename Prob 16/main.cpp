// Power digit sum

#include "stdafx.h"
#include <stdio.h>
int r[1001], d, sum = 0;
unsigned char flag;
int main() {
	d = 1;
	flag = 1;
	while (flag == 1) {
		flag = 0;
		for (int i = 1; i <= 1000; i++) {
			d = d * 2 + r[i];
			r[i] = d / 10;
			if (r[i] > 0) flag = 1;
			d = d % 10;
		}
		sum += d;
		d = 0;
	}
	printf("%d\n", sum);
	return 0;
}

