#include <math.h>

int isPrime(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    int limit = (int)sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int PrimeCount(int A, int B) {
    int count = 0;
    for (int i = A; i <= B; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    return count;
}
