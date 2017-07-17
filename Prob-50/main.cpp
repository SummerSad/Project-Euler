#include <stdio.h>
#include <stdlib.h>

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

int nextPrime(int p)
{
    int temp = p + 1;
    while (!isPrime(temp)) {
        temp++;
    }
    return temp;
}

void pri(int *A, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

//  longest sum of consecutive primes that adds to a prime
//  below MAX
int sumConsePrime(int MAX)
{
    int max_count = 0;
    int max_sum = 0;
    for (int p = 2; p < MAX; p = nextPrime(p)) {
        int sum = 0;
        int count = 0;
        int temp = p;
        while (sum < MAX) {
            sum += temp;
            temp = nextPrime(temp);
            if (isPrime(sum) && sum < MAX && count > max_count) {
                max_count = count;
                max_sum = sum;
            }
            count++;
        }
    }
    return max_sum;
}

int main()
{
    printf("%d\n", sumConsePrime(1000000));
    return 0;
}
