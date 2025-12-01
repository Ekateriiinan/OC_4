#include <math.h>

float Derivative(float A, float deltaX) {
    float f_A_plus = cosf(A + deltaX);
    float f_A_minus = cosf(A - deltaX);
    return (f_A_plus - f_A_minus) / (2 * deltaX);
}