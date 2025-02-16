t = int(input())

for _ in range(t):
    q, m = map(int, input().split())
    now = 1
    gl = [0] * (q + 5)

    for i in range(1, q+1):
        op, x = map(int, input().split())
        if op == 1:
            gl[i] = x
            now *= x
            print(now % m)
        else:
            now //= gl[x]
            print(now % m)
