#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 999

//What is the sum of the digits of the number 2^1000?
//The idea is: We don't deal with Big Num, we deal with strings my friends.

void reverse(char s[])
{
	int i, j;
	char sth;
	for (i = 0, j = strlen(s) - 1; i < j; ++i, --j)
	{
		sth = s[i];
		s[i] = s[j];
		s[j] = sth;
	}
}

// multi num by 2
void multi2_string(char s[], char result[])
{
	char t[MAX];
	int i, sth;
	for (i = 0; i < strlen(s); ++i)
		t[i] = s[i];
	t[strlen(s)] = '\0';
	reverse(s); reverse(t);
	for (result[0] = '0', i = 0; i < strlen(s); ++i)
	{
		sth = result[i] - '0' + s[i] - '0' + t[i] - '0';
		result[i] = sth % 10 + '0';
		result[i + 1] = sth / 10 + '0';
	}
	result[i] = '\0';
	reverse(result);
}

int sum_digit(char s[])
{
	int i, sum;
	sum = 0;
	for (i = 0; i < strlen(s); ++i)
		if (isdigit(s[i]))
			sum += s[i] - '0';
	return sum;
}

int main(void)
{
	int i = 0;
	//creat string
	char s[MAX], t[MAX];
	for (i = 0; i < MAX - 2; ++i)
		s[i] = '0';
	s[MAX - 2] = '1'; s[MAX - 1] = '\0';
	//let's have 2^1000
	for (i = 0; i < 500; ++i)
	{
		multi2_string(s, t);
		multi2_string(t, s);
	}
	//result
	printf("%d\n", sum_digit(s));
}