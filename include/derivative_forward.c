#include <math.h>

float Derivative(float A, float deltaX) {
    float f_A_plus = cosf(A + deltaX);
    float f_A = cosf(A);
    return (f_A_plus - f_A) / deltaX;
}