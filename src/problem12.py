# Project Euler #12
import math
import time

def triangle(n):
    return n * (n + 1) // 2

def perfect_square(n):
    return (round(math.sqrt(n)) ** 2) == n

def factor_count(n):
    factors = 0

    for i in range(1, round(math.sqrt(n) + 1)):
        if n%i == 0:
            factors += 1

    if perfect_square(n):
        return (factors * 2) - 1
    else:
        return factors * 2

    return factors 

def factor2(n):
    even = lambda n: n % 2 == 0
    if even(n):
        return factor2(n / 2) * factor2(n + 1)
    elif even(n + 1):
        return factor2(n) * factor2((n + 1) / 2)

n = 1
start = time.time()
while True:
    number = triangle(n)
    n += 1
    factors = factor_count(number)
    if factors > 500:
        end = time.time()
        print(number)
        print("Elapsed time: {}".format(end - start))
        break
