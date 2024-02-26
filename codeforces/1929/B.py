t = int(input())
for _ in range(t):
    n, k = list(map(int,input().split()))
    if k <= 4 * n - 4:
        print((k + 1) // 2)
    else:
        print(k-(4*n-4) + 2*n-2)