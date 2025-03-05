n = 61
print(3, n)
print(' '.join(map(str, [0] * n)))
print(' '.join(map(str, [(1<<i) for i in range(n-1)] + [0])))
print(' '.join(map(str, [0] * n)))

q = int(input())
for _ in range(q):
    x = int(input())
    u = True
    for i in range(n-1):
        if x & (1 << i):
            if u:
                print('DD', end='')
            else:
                print('UU', end='')
            u = not u
        print('R', end='')
    if u:
        print('DD', end='')
    print()
