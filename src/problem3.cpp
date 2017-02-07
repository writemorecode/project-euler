#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

bool is_factor(int a, int b) {
    return (a % b == 0);
}

bool is_factor(long long a, long long b) {
    return (a % b == 0);
}

bool is_prime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }

    for (int i = 2; i < std::sqrt(n); i++) {
        if (is_factor(n, i)) {
            return false;
        }
    }

    return true;
}

std::vector<int> primes_below(long long n) {
    std::vector<int> primes;

    for (int x = 2; x < std::sqrt(n); x++) {
        if (is_prime(x)) {
            primes.push_back(x);
        }
    }

    return primes;
}

std::vector<int> find_prime_factors(std::vector<int> primes, long long n) {
    std::vector<int> prime_factors;
    for (long long p : primes) {
        if (is_factor(n, p)) {
            prime_factors.push_back(p);
        }
    }

    return prime_factors;
}

int main(void) {
    long long num = 600851475143;
    std::vector<int> p = primes_below(num);
    std::vector<int> pf = find_prime_factors(p, num);

    int largest = *std::max_element(pf.begin(), pf.end());
    std::cout << largest << std::endl;


    return 0;
}