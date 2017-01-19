#include "func.h"

int sum_pd(int n)
{
	int re,i;
	for(re=0,i=1;i*2<=n;++i)
		if(n%i==0)
			re+=i;
	return re;
}