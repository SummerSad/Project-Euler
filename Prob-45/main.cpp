#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Find the next triangle number that is also pentagonal and hexagonal
//40755

bool isPenta(long long Pn)
{
	if(Pn < 1)
		return false;
	long long n = ((long long)sqrt(Pn * 6) + 1) / 3;
	return n * (3 * n - 1) / 2 == Pn;
}

bool isHexa(long long Hn)
{
	if(Hn < 1)
		return false;
	long long n = ((long long)sqrt(Hn * 2) + 1) / 2;
	return n * (2 * n - 1) == Hn;
}

void creTri(long long MAX, long long *&T, long long &size)
{
	long long i, j;
	for(i = 1, j = 0; i * (i + 1) / 2 <= MAX; i++)
	{
		T = (long long *)realloc(T, sizeof(long long) * (j + 1));
		T[j++] = i * (i + 1) / 2;
	}
	size = j;
}

void findDupli(long long MIN, long long MAX)
{
	long long *T = NULL;
	long long size = 0;
	creTri(MAX, T, size);
	for(long long i = 0; i < size; i++)
	{
		if(T[i] > MIN && isPenta(T[i]) && isHexa(T[i]))
		{
			printf("%ld\n", T[i]);
		}
	}
	free(T);
}

int main()
{
	findDupli(40755, 10000000000);
	return 0;
}
