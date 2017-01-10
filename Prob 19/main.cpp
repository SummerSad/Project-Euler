// Counting Sundays
#include <stdio.h>

struct ngay
{
	int dd;
	int mm;
	int yy;
};

int list[2][12]=
{
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31},
};

int nhuan(int year) // Kiem tra nam nhuan
{
	if(year%4==0 && year%100 != 0 || year%400 == 0)
		return 1;
	return 0;
}

ngay next(ngay A)  // Ngay tiep theo
{
	ngay tam;
	if(A.dd == 31 && A.mm == 12)
		{
			tam.dd=1;
			tam.mm=1;
			tam.yy=A.yy+1;
			return tam;
		}
	if(A.dd+1>list[nhuan(A.yy)][A.mm-1])
		{
			tam.dd=1;
			tam.mm=A.mm+1;
			tam.yy=A.yy;
			return tam;
		}
	else
	{
		tam.dd=A.dd+1;
		tam.mm=A.mm;
		tam.yy=A.yy;
		return tam;
	}
}

void copyday(ngay &A,ngay B)
{
	A.dd=B.dd;
	A.mm=B.mm;
	A.yy=B.yy;
}

void next_t(ngay &A) // Cong don A vao ngay tiep theo
{
	copyday(A,next(A));
}

void next_k(ngay &A, int k)
{
	for(int i=0;i<k;++i)
		next_t(A);
}

int main(void)
{
	ngay A;
	A.dd=7;A.mm=1;A.yy=1900;
	while(A.yy==1900)
		next_k(A,7); // A se la ngay chu nhat trung dau thang cua nam 1901
	int count=0;
	while(A.dd!=7 || A.mm!=1 || A.yy!=2001) // qua 2001 thi ket thuc
	{
		next_k(A,7);
		if(A.dd==1)
			++count;
	}
	printf("%d\n",count);
}

