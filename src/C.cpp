#include "../include/prototype.h"

#include <limits>   // For quiet_NaN()

double calculate_exp(double x, long n)
{
    // Handle zero base
    if (x == 0.0) {
        // 0^positive -> 0; 0^0 or 0^negative -> not defined (return NaN)
        return (n > 0) ? 0.0 : std::numeric_limits<double>::quiet_NaN();
    }

    // x^0 = 1
    if (n == 0) {
        return 1.0;
    }

    // Track if exponent is negative, work with its absolute value
    bool negativeExponent = (n < 0);
    if (negativeExponent) {
        n = -n;  // Make exponent positive for processing
    }

    double result = 1.0;

    // Exponentiation by squaring
    while (n > 0) {
        if (n & 1) {      // If n is odd, multiply result by x
            result *= x;
        }
        x *= x;           // Square the base
        n >>= 1;          // Divide exponent by 2
    }

    // If original exponent was negative, return 1/result
    return negativeExponent ? 1.0 / result : result;
}

