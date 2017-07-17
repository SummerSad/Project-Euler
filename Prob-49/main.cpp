#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPrime(int n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permu(char *str, int l, int r, int *&A, int &size)
{
    if (l == r) {
        A = (int *)realloc(A, sizeof(int) * (size + 1));
        A[size++] = atoi(str);
    }
    else {
        for (int i = l; i <= r; i++) {
            swap(str + l, str + i);
            permu(str, l + 1, r, A, size);
            swap(str + l, str + i);
        }
    }
}

void pri(int *A, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

bool isPrimePermu(int n)
{
    if (!isPrime(n)) return false;
    char *str = NULL;
    int len = 0;
    int temp = n;
    while (temp > 0) {
        str = (char *)realloc(str, sizeof(char) * (len + 1));
        str[len++] = '0' + temp % 10;
        temp /= 10;
    }
    str[len] = '\0';

    // reverse to convert n to str
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // make an array contain permutation numbers
    int *A = NULL;
    int size = 0;
    permu(str, 0, len - 1, A, size);

    // remove not prime number
    for (int i = 0; i < size; i++) {
        if (!isPrime(A[i]) || A[i] < 1000) {
            for (int j = i; j < size - 1; j++) {
                A[j] = A[j + 1];
            }
            if (A) A = (int *)realloc(A, sizeof(int) * (size - 1));
            size--;
            i--;
        }
    }
    if (size < 3)  // not enough
        return false;
    // check arithmetic sequence
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            for (int k = j + 1; k < size; k++) {
                if (A[i] != A[j] && A[j] != A[k] && A[k] != A[i]) {
                    if (A[i] + A[j] == 2 * A[k] || A[j] + A[k] == 2 * A[i] ||
                        A[k] + A[i] == 2 * A[j]) {
                        printf("%d %d %d\n", A[i], A[j], A[k]);
                        return true;
                    }
                }
            }
        }
    }
    // free memory
    free(str);
    str = NULL;
    free(A);
    A = NULL;
    return false;
}

int main()
{
    for (int i = 1000; i <= 9999; i++) {
        if (isPrimePermu(i))
            ;
    }
    return 0;
}
