// sum of all the amicable numbers under 10000.

#include "func.h"

int main(void)
{
	int i,re;
	for(re=0,i=2;i<10000;++i)
		// there are some perfect numbers;
		// such as 6,28..
		// we need to minus them
		if(sum_pd(i)!=i && sum_pd(sum_pd(i))==i) 
			re+=i;
	printf("%d\n",re);
	return 0;
}