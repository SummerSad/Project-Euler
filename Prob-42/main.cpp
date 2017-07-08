#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100
//how many are triangle words?

bool isTriangle(int n)
{
	if(n <= 0)
		return false;
	int temp = (int)sqrt(n * 2);
	return temp * (temp + 1) / 2 == n;
}

int countTriWord(char *filename)
{
	FILE *f = fopen(filename, "r");
	if(f == NULL)
	{
		printf("No Files\n");
		return 0;
	}
	int count = 0;
	char c;
	int temp = 0;
	while((c = fgetc(f)) != EOF)
	{
		if(c >= 'A' && c <= 'Z')
		{
			temp += c - 'A' + 1;
		}
		else
		{
			if(isTriangle(temp))
				count++;
			temp = 0;
		}
		//printf("%d %d\n", temp, count);
	}
	fclose(f);
	return count;
}

int main()
{
	printf("%d\n", countTriWord("words.txt"));
	return 0;
}
