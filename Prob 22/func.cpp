#include "func.h"

int value(char s[])
{
	int val = 0;
	for (int i = 0; s[i] != '\0'; ++i)
		if (s[i] >= 'A' && s[i] <= 'Z')
			val += s[i] - 'A' + 1;
	return val;
}

void copy_s(char s[], char t[])
{
	int i;
	for (i = 0; i < strlen(t); ++i)
		s[i] = t[i];
	s[i] = '\0';
}

void swap(char s[], char t[])
{
	char sth[MAX];
	copy_s(sth, s);
	copy_s(s, t);
	copy_s(t, sth);
}