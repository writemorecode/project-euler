/**
 * Project Euler
 * Problem 4 - Largest palindrome product
 *  
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>

bool is_palindromic_number(int n) {
    std::stringstream ss;
    ss << n;
    std::string s = ss.str();
    std::string rev(s);
    std::reverse(rev.begin(), rev.end());

    if (s.compare(rev) == 0) {
        return true;
    }

    return false;
}

int largest_palindromic_product() {
    int largest = 0;
    for (int x = 100; x < 999; x++) {
        for (int y = 100; y < 999; y++) {
            int product = x * y;
            if (is_palindromic_number(product)) {
                if (product > largest) {
                    largest = product;
                }
            }
        }
    }

    return largest;
}

int main() {
    int result = largest_palindromic_product();
    std::cout << result << std::endl;

    return 0;
}