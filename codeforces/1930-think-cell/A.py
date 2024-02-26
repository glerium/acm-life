t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    a.sort()
    for i in range(0, 2*n, 2):
        ans += a[i]
    print(ans)