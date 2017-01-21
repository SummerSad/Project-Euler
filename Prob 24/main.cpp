// Lexicographic permutations
// 012 -> 021 -> 102 -> 120 -> 201 -> 210
#include "func.h"

int main(void)
{
	char s[] = "0123456789";
	for (int i = 1; i < 1000000; ++i)
		next(s);
	puts(s);
	return 0;
}