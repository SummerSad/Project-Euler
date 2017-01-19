// find sum of digits of 100!
#include <stdio.h>
#define MAX 500

int sum(int arr[],int len);

int main(void)
{
	int arr[MAX]={0};arr[0]=1; // start from 100..0
	int i,j,rem,x,y; // rem : remand
	for(i=2;i<100;++i) // 100!
	{
		for(rem=0,j=0;j<MAX;++j)
		{
			x=arr[j]*i+rem;
			arr[j] = x % 10;
			rem = x / 10; 
		}
	}
	printf("Sum digits 100!: %d\n",sum(arr,MAX));
	return 0;
}

int sum(int arr[],int len)
{
	int i,re;
	for(re=0,i=0;i<len;++i)
		re+=arr[i];
	return re;
}