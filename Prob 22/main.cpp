#include "func.h"

int main(void)
{
	int i, j; long int re;
	FILE *f = fopen("names.txt", "r");
	if (f == NULL)
		return 0;
	char store[5163][MAX];
	for (i = 0; i < 5163; ++i)
		fscanf(f, "%s", &store[i]);
	fclose(f);

	// use strcmp to compare 2 string
	for (i = 0; i < 5163; ++i)
		for (j = i + 1; j < 5163; ++j)
			if (strcmp(store[i], store[j]) > 0)
				swap(store[i], store[j]);

	for (re = 0, i = 0; i < 5163; ++i)
		re += value(store[i])*(i + 1);
	printf("%d\n", re);
	return 0;
}