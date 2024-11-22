# n,a,b = map(int,input().split())

import random
for ee in range(100):
    n = random.randint(1, 1000)
    a = random.randint(0, 10)
    b = random.randint(a, 100)
    x = 0
    y = 0
    l = []
    xx = n * a // b
    yy = n - 1 - xx
    if xx * b <= a * (xx+yy):
        tmp = 1
    else:
        tmp = 0
    for _ in range(n):
        if _ == 0:
            x += 1
            l.append(1)
        elif x*b <= (x+y)*a:
            x += 1
            l.append(1)
        else:
            y += 1
            l.append(0)
    print(tmp, sum(l) - n*a//b)
