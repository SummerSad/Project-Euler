// What is the index of the first term in the Fibonacci sequence
// to contain 1000 digits?
#include <stdio.h>
#define MAX 1000
void copycat(int from[], int to[], int len);

// s = s + t
// t = s
//  1 1 -> 2 1 -> 3 2 -> 5 3
void plus(int s[], int t[], int len);

// count real digits
int count_digit(int s[], int len);

int main(void)
{
	int s[1000] = { 1 }; int t[1000] = { 1 };
	int i = 2;

	while (count_digit(s, 1000) < 1000)
	{
		plus(s, t, 1000);
		++i;
	}
	printf("%d\n", i);
	return 0;
}
int count_digit(int s[], int len)
{
	int i = len;
	while (s[i - 1] == 0)
		--i;
	return i;
}

void copycat(int from[], int to[], int len)
{
	for (int i = 0; i < len; ++i)
		to[i] = from[i];
}

void plus(int s[], int t[], int len)
{
	int i, x, rem;
	int sth[MAX];

	copycat(s, sth, 1000);

	for (rem = 0, i = 0; i < len; ++i)
	{
		x = s[i] + t[i] + rem;
		s[i] = x % 10;
		rem = x / 10;
	}

	copycat(sth, t, 1000);
}