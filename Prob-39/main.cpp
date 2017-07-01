#include <stdio.h>

//If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}
//there are exactly three solutions for p = 120.
//{20,48,52}, {24,45,51}, {30,40,50}

int countSolution(int n)
{
	int solution = 0;
	for(int i = 1; i <= n / 3; i++)
	{
		for(int j = i + 1; j <= n / 2; j++)
		{
			int k = n - i - j;
			if(i * i + j * j == k * k)
			{
				//printf("%d %d %d\n", i, j, k);
				solution++;
			}
		}
	}
	return solution;
}

int max_p(int MAX)
{
	int solutionMax = 0;
	int p = 0;
	for(int i = 1; i <= MAX; i++)
	{
		if(countSolution(i) > solutionMax)
		{
			solutionMax = countSolution(i);
			p = i;
		}
	}
	return p;
}

int main()
{
	printf("%d\n", max_p(1000));
	return 0;
}
