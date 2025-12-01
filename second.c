#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

float (*Derivative)(float, float);
int (*PrimeCount)(int, int);

void* handle_derivative;
void* handle_primecount;

void solve() {
    int number_of_function;
    scanf("%d", &number_of_function);

    if (number_of_function == 1) {
        float A, deltaX;
        scanf("%f %f", &A, &deltaX);

        float result = (*Derivative)(A, deltaX);
        printf("Derivative of cos(x) at x = %f is approximately %f\n", A, result);
    } else {
        int A, B;
        scanf("%d %d", &A, &B);

        int result = (*PrimeCount)(A, B);
        printf("Prime numbers count in [%d, %d] = %d\n", A, B, result);
    }
}

void load_libraries() {
    int realization;
    scanf("%d", &realization);

    if (realization == 0) {
        handle_derivative = dlopen("./libraries/libderivative_forward.so", RTLD_LAZY);
        handle_primecount = dlopen("./libraries/libprimecount_naive.so", RTLD_LAZY);
    } else {
        handle_derivative = dlopen("./libraries/libderivative_central.so", RTLD_LAZY);
        handle_primecount = dlopen("./libraries/libprimecount_sieve.so", RTLD_LAZY);
    }

    if (!handle_derivative) {
        fprintf(stderr, "Error loading derivative library: %s\n", dlerror());
        exit(1);
    }
    if (!handle_primecount) {
        fprintf(stderr, "Error loading primecount library: %s\n", dlerror());
        exit(1);
    }
    dlerror();

    Derivative = dlsym(handle_derivative, "Derivative");
    PrimeCount = dlsym(handle_primecount, "PrimeCount");

    char* error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "Error loading symbols: %s\n", error);
        exit(1);
    }
}

void close_libraries() {
    dlclose(handle_derivative);
    dlclose(handle_primecount);
}

int main() {
    load_libraries();
    solve();
    close_libraries();
    return 0;
}
