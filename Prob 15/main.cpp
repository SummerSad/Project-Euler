// Problem 15   Lattice Paths
#include <stdio.h>
int i, j;
unsigned char a[22][22][20];
// addition of two bignum, maximum 20 digit.
void sum(unsigned char a[20],unsigned char b[20], unsigned char c[20]) {
	int k, r, d, l;
	if (b[0] > c[0]) {
		l = b[0];
	} else l = c[0];
	r = 0;
	for (k = 1; k <= l; k++) {
		d = b[k] + c[k] + r;
		r = d / 10;
		a[k] = d % 10;
	}
	if (r > 0) {
		l++;
		a[l] = r;
	}
	a[0] = l;
}
int main() {
	for (i = 1; i <= 21; i++) {
		a[i][1][1] = 1;
		a[i][1][0] = 1;
	}
	for (j = 2; j <= 21; j++) {
		for (i = 1; i <= 21; i++) {
			sum(a[i][j],a[i][j - 1],a[i - 1][j]); // a[i][j]=a[i-1][j]+a[i][j-1]
		}
	}
	for (i = a[21][21][0]; i >= 1; i--) {
		printf("%d", a[21][21][i]);
	}  // print result..
	printf("\n");
	return 0;
}

