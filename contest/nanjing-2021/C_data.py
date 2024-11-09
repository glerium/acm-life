import random

with open("in.txt", 'w') as f:
    f.write('1\n')
    n = 1000000
    f.write(f'{n}\n')
    for i in range(n):
        x = random.randint(-1e9, 1e9)
        y = random.randint(-1e9, 1e9)
        f.write(f'{x} {y}\n')
    