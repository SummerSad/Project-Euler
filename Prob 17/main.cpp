//letters count from 1 to 1000
#include <stdio.h>
#define MAX

int below20[20]={0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8}; // letters count from 1 to 19
int the10s[8]={6,6,5,5,5,7,6,6}; // letters count: X0 (ex 20,30..)

int countw(int num);

int main(void)
{
	int count,i;
	count=0;
	for(i=1;i<1000;++i)
		count+=countw(i);
	count+=11; // one thousand
	printf("%d\n",count);
	return 0;
}

int countw(int num)
{	
	if(num>=0 && num<20)
		return below20[num];
	else if(num>=20 && num<100)
		return the10s[num/10-2]+below20[num%10];
	else if(num>=100 && num<1000)
	{
		if(num%100==0)
			return below20[num/100]+7;
		return countw((num/100)*100)+3+countw(num%100); 
	}
	else
		return 0; // out of range
}
