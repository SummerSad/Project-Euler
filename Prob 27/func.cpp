#include "func.h"

int is_prime(int n)
{
	if(n<=1)
		return 0;
	for(int i=2;i*i<=n;++i)
		if(n%i==0)
			return 0;
	return 1;
}

int count(int a, int b)
{
	int i,re;
	for(re=0,i=0;is_prime(i*i+a*i+b);++i)
		++re;
	return re;
}
