#include "../include/prototype.h"

#include <iostream>
#include <stdexcept>

double calculate_exp(double x, long n) {
    // Handle edge cases
    if (n < 0) {
        // For negative exponents, return the reciprocal of the positive exponent
        return 1.0 / calculate_exp(x, -n);
    }
    if (n == 0) {
        // Any number to the power of 0 is 1
        return 1.0;
    }
    if (x == 0.0 && n == 0) {
        // 0^0 is undefined, but we can return 1 as a common convention
        return 1.0;
    }

    double result = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            // If n is odd, multiply the result by x
            result *= x;
        }
        // Square x and halve n
        x *= x;
        n /= 2;
    }

    return result;
}

/*
int main() {
    double base = 2.0;
    long exponent = 10;
    std::cout << "Result: " << calculate_exp(base, exponent) << std::endl;
    return 0;
}
*/
