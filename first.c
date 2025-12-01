#include <stdio.h>

#include "include/derivative_forward.c"
#include "include/primecount_naive.c"

void solve() {
    int number_of_function;
    scanf("%d", &number_of_function);

    if (number_of_function == 1) {
        float A, deltaX;
        scanf("%f %f", &A, &deltaX);

        float result = Derivative(A, deltaX);
        printf("Derivative of cos(x) at x = %f is approximately %f\n", A, result);
    } else {
        int A, B;
        scanf("%d %d", &A, &B);

        int result = PrimeCount(A, B);
        printf("Prime numbers count in [%d, %d] = %d\n", A, B, result);
    }
}

int main() {
    solve();
    return 0;
}
