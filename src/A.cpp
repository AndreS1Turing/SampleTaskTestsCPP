#include "../include/prototype.h"

double calculate_exp(double x, long n) {
    // Handle edge cases
    if (n == 0) return 1.0;
    if (x == 0.0) return 0.0;
    if (x == 1.0) return 1.0;
    
    // Handle negative exponents
    if (n < 0) {
        x = 1.0 / x;
        n = -n;
    }
    
    double result = 1.0;
    
    // Binary exponentiation algorithm
    while (n > 0) {
        // If current bit is 1, multiply result by current x
        if (n & 1) {
            result *= x;
        }
        // Square x for next bit
        x *= x;
        // Shift to next bit
        n >>= 1;
    }
    
    return result;
}
