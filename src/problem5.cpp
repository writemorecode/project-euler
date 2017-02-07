#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
#include <algorithm>

/**
 * Calculates the greatest common divisor of a and b
 * using the Euclidean algorithm
 * 
 * gcd(a,0) = a
 * gcd(a,b) = gcd(b, a % b)
 */
long greatest_common_divisor(long a, long b) {
    if (b == 0) {
        return a;
    } else {
        return greatest_common_divisor(b, a % b);
    }
}

long least_common_multiple(long a, long b) {
    return std::abs(a * b) / greatest_common_divisor(a, b);
}

int main(void) {

    long multiple = 1;
    for (int i = 2; i < 20; i++) {
        multiple = least_common_multiple(multiple, i);

    }
    std::cout << multiple << std::endl;

    return 0;
}