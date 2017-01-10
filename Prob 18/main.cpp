#include <stdio.h>
#define MAX 100

//    1
//  2  3
// 1  4  5
// max path is 1+3+5=9

int power(int a,int n); // return a^n;

int max_path(int arr[MAX][MAX],int hang,int cot); 

int main(void)
{
	int arr[MAX][MAX]={
		{75},
		{95, 64},
		{17, 47, 82},
		{18, 35, 87, 10},
		{20,  4, 82, 47, 65},
		{19,  1, 23, 75,  3, 34},
		{88,  2, 77, 73,  7, 63, 67},
		{99, 65,  4, 28,  6, 16, 70, 92},
		{41, 41, 26, 56, 83, 40, 80, 70, 33},
		{41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
		{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
		{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
		{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
		{63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
		{ 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}
	};
	
	printf("%d\n",max_path(arr,15,15));
	return 0;
}

int power(int a,int n)
{
	int result=1;
	for(int i=0;i<n;++i)
		result*=a;
	return result;
}

// idea is to use the binary 
int max_path(int arr[MAX][MAX],int hang,int cot)
{
	int i,j,k,max,tam,a,b;
	max=0;
	for(i=0;i<power(2,cot-1);++i) // Trace all possible route
	{
		j=0;k=0; // arr[j][k] from start
		a=i;b=cot-1;
		tam=arr[j][k];
		while(b>0)
		{
			if(!(a&1))
			{
				++j;
				tam+=arr[j][k];
			}
			else
			{
				++j;++k;
				tam+=arr[j][k];
			}
			a=a>>1;
			--b;
		}
		if(tam>max)
			max=tam;
	}
	return max;
}

