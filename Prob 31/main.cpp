#include <stdio.h>

int main(void)
{
	int a1, a2, a5, a10, a20, a50, a100, count = 1;
	for (a1 = 0; a1 <= 200; ++a1)
		for (a2 = 0; a2 <= 100; ++a2)
			for (a5 = 0; a5 <= 40; ++a5)
				for (a10 = 0; a10 <= 20; ++a10)
					for (a20 = 0; a20 <= 10; ++a20)
						for (a50 = 0; a50 <= 4; ++a50)
							for (a100 = 0; a100 <= 2; ++a100)
								if (a1 + a2 * 2 + a5 * 5 + a10 * 10 + a20 * 20 + a50 * 50 + a100 * 100 == 200)
									++count;
	printf("%d\n", count);
	return 0;
}