#include "../include/prototype.h"
#include <limits>
#include <iostream>
double calculate_exp(double x, long n)
{

    // Negative exponents are the inverse of the positive exponents
    if (n < 0)
    {
        return 1.0 / calculate_exp(x, -n);
    }

    
    // We only need to calculate other exponents. 'ret' will hold the result.
    double ret = 1.0;
    
    while (n > 0)
    {
        // For odd exponent elements we perform a multiplication
        if (n  % 2)
        {
            ret *= x;
        }
        x *= x;
        n /= 2;
    }
    return ret;
}

// Helper function to print the results of the functions.
void print_resut(double x, long n)
{
    std::cout << x << " raised to the power of " << n << " is " << calculate_exp(x, n) << "." << std::endl;
}

/* int main()
{
    // Sample executions:
    double value = calculate_exp(3, 3);
    print_resut(3, 3);
    print_resut(2, 3);
    print_resut(2, -2);
    print_resut(0, 0);
    print_resut(0, -2);
    print_resut(5, -3);
    print_resut(10, 6);
    return 0;
} */
