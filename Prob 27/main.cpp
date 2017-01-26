#include "func.h"

int main(void)
{
	int a,b,max_p,max_m;
	// max_p is max primes
	// max_m is max products
	for(max_p=0,a=-999;a<=999;++a)
		for(b=-1000;b<=1000;++b)
			if(count(a,b)>max_p)
			{
				max_p=count(a,b);
				max_m=a*b;
			}
	printf("%d\n",max_m);
}