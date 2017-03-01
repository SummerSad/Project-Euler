#include "iostream"
#include "memory"
using namespace std;

// Prob 32: https://projecteuler.net/problem=32  
//1 4 4
//2 3 4
int a[10];
int c[10];
int trace[100];
int d_trace = 0;

void DanhDau(int x) {
	int d;
	while (x > 0) {
		d = x % 10;
		a[d] = 1;
		x = x / 10;
	}
}

void BoDanhDau(int x) {
	int d;
	while (x > 0) {
		d = x % 10;
		a[d] = 0;
		x = x / 10;
	}
}

bool ok(int n, int a[10])
{
	int d;
	for (int i = 1; i <= 9; i++) c[i] = a[i];
	while (n > 0)
	{
		d = n % 10;
		if (d == 0) return false;
		if (c[d] == 1) return false;
		else c[d] = 1;
		n = n / 10;
	}
	return true;
}

bool check(int x) {
	for (int i = 1; i <= d_trace; i++) {
		if (trace[i] == x) return false;
	}
	return true;
}

int main()
{
	int product;
	int count = 0;
	memset(a, 0, sizeof(a));
	for (int i = 2; i <= 9; i++)
	{
		a[i] = 1;
		for (int j = 1234; j <= 9876; j++)
		{
			if (ok(j, a) == true)
			{
				DanhDau(j);
				product = i*j;
				if (product > 9876) {
					BoDanhDau(j);
					break;
				}
				if ((ok(product, a) == true) && (check(product) == true))
				{
					d_trace++;
					trace[d_trace] = product;
					count += product;
					cout << i << "x" << j << "=" << product << endl;
				}
				BoDanhDau(j);
			}
		}
		a[i] = 0;
	}

	for (int i = 12; i <= 98; i++) if (ok(i, a) == true)
	{
		DanhDau(i);
		for (int j = 123; j <= 987; j++)
		{
			if (ok(j, a) == true)
			{
				DanhDau(j);
				product = i*j;
				if (product > 9876) {
					BoDanhDau(j);
					break;
				}
				if ((ok(product, a) == true) && (check(product) == true))
				{
					d_trace++;
					trace[d_trace] = product;
					count += product;
					cout << i << "x" << j << "=" << product << endl;
				}
				BoDanhDau(j);
			}
		}
		//a[i] = 0;
		BoDanhDau(i);
	}
	cout << "Sum of all products: " << count << endl;
	system("pause");
	return 0;
}

