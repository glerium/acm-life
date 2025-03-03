t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1:
        print(-1)
    elif n == 2:
        print('2 1')
    else:
        print(' '.join(map(str, [2,1] + list(range(3, n+1)))))
