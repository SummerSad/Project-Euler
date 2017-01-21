#include "func.h"

void swap(char s[], int i, int j)
{
	char sth;
	sth = s[i];
	s[i] = s[j];
	s[j] = sth;
}

void arrange(char s[], int from, int to)
{
	int i, j; char sth;
	for (i = from; i <= to; ++i)
		for (j = i + 1; j <= to; ++j)
			if (s[i] > s[j])
				swap(s, i, j);
}

int right_m(char s[])
{
	int i, re;
	for (i = 0; s[i + 1] != '\0'; ++i)
		if (s[i] < s[i + 1])
			re = i;
	return re;
}

int ceiling(char s[])
{
	int i, re;
	i = right_m(s) + 1;
	re = i;
	for (; s[i] != '\0'; ++i)
		if (s[i] > s[right_m(s)] && s[i] < s[re])
			re = i;
	return re;
}

void next(char s[])
{
	int i, j;
	i = right_m(s); j = ceiling(s);
	swap(s, i, j);
	arrange(s, i + 1, strlen(s) - 1);
}