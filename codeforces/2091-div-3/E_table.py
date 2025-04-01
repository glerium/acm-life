from math import gcd

primes = [2, 3, 5, 7, 11, 13, 17]

n = 10
for x in range(1, n+1):
    for y in range(x+1, n+1):
        g = gcd(x, y)
        l = x * y // g
        if l // g in primes:
            print(x, y)
