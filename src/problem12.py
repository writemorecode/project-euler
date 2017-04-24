# Project Euler #12

import math

def triangle(n):
    """ Computes the nth triangle number. """
    return n * (n + 1) // 2

def perfect_square(n):
    """ Checks if n is a perfect square. """
    return (round(math.sqrt(n)) ** 2) == n

def factor_count(n):
    """ Computes the number of factors of n. """
    factors = 0

    for i in range(1, round(math.sqrt(n) + 1)):
        if n%i == 0:
            factors += 1

    if perfect_square(n):
        return (factors * 2) - 1
    else:
        return factors * 2

    return factors 

n = 1
while True:
    number = triangle(n)
    n += 1
    factors = factor_count(number)
    if factors > 500:
        print(number)
        break
