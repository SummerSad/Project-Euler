#include <stdio.h>

struct Frac
{
	int up, down;
};

Frac strim(Frac X)
{
	int temp_a = X.up;
	int temp_b = X.down;
	while(temp_a && temp_b)
	{
		if(temp_a > temp_b)
			temp_a = temp_a - temp_b;
		else
			temp_b = temp_b - temp_a;
	}
	int d = temp_a > temp_b ? temp_a : temp_b;
	return Frac
	{
		X.up / d, X.down / d
	};
}

// up and down has 2 digits
bool is_2Digit(Frac X)
{
	if(X.up < 10 || X.up > 99)
		return false;
	if(X.down < 10 || X.down > 99)
		return false;
	if(X.up >= X.down)
		return false;
	return true;
}

bool isEqual(Frac X, Frac Y)
{
	if(X.down == 0 || Y.down == 0)
		return false;
	return (X.up * Y.down == X.down * Y.up);
}

bool isCurious(Frac X)
{
	// ab/cd ?= a/c ?= b/d ?= a/d ?= b/c
	if(X.up % 10 == 0 && X.down % 10 == 0) // easy to see
		return false;
	if(is_2Digit(X))
	{
		if(X.up % 10 == X.down % 10)
		{
			Frac a_c = {X.up / 10, X.down / 10};
			if(isEqual(X, a_c))
				return true;
		}
		if(X.up / 10 == X.down / 10)
		{
			Frac b_d = {X.up % 10, X.down % 10};
			if(isEqual(X, b_d))
				return true;
		}
		if(X.up % 10 == X.down / 10)
		{
			Frac a_d = {X.up / 10, X.down % 10};
			if(isEqual(X, a_d))
				return true;
		}
		if(X.up / 10 == X.down % 10)
		{
			Frac b_c = {X.up % 10, X.down / 10};
			if(isEqual(X, b_c))
				return true;
		}
	}
	return false;
}

int main()
{
	Frac result = {1, 1};
	for(int i = 10; i <= 99; i++)
	{
		for(int j = 10; j <= 99; j++)
		{
			Frac X = {i, j};
			if(isCurious(X))
			{
				printf("%d\\%d\n", X.up, X.down);
				result.up *= X.up;
				result.down *= X.down;
			}
		}
	}
	printf("%d\n", strim(result).down);
	return 0;
}
