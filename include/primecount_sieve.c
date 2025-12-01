#include <stdlib.h>
#include <string.h>

int PrimeCount(int A, int B) {
    if (B < 2) return 0;
    if (A < 2) A = 2;
    
    int size = B + 1;
    char* sieve = (char*)malloc(size * sizeof(char));
    if (!sieve) return -1;
    
    memset(sieve, 1, size);
    sieve[0] = sieve[1] = 0;
    
    for (int i = 2; i * i <= B; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= B; j += i) {
                sieve[j] = 0;
            }
        }
    }
    
    int count = 0;
    for (int i = A; i <= B; i++) {
        if (sieve[i]) count++;
    }
    
    free(sieve);
    return count;
}