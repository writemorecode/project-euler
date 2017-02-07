/**
 * Project Euler
 * Problem 2 - Even Fibonacci numbers
 */

#include <iostream>
#include <vector>

int even(int n) {
    return (n % 2 == 0);
}

int main(void) {
    /**
     * Quick fibonacci number generation using vectors.
     * Generating fibonacci numbers this way is efficient because
     * each number in the series only needs to be computed once.
     */

    std::vector<int> fib_series = {1, 1};
    /**
     * Iterator pointing to the "past-the-end" element  of the vector
     * (not the last element, which in this case would be 1)
     */

    std::vector<int>::iterator it = fib_series.end();

    int sum = 0;

    while (1) {
        /**
         * Because the iterator is pointing to an element which is past the end of the vector,
         * we need to move back one step to the real last element.
         */
        it--;
        // Element at the end of the vector
        int a = *it;
        it--;
        // Second to last element in the vector
        int b = *it;
        int c = a + b;
        fib_series.push_back(c);
        // Reset iterator to end of vector
        it = fib_series.end();

        if (c >= 4000000) {
            break;
        }

        if (even(c)) {
            sum += c;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
