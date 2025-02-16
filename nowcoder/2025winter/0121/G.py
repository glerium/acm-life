n = int(input())
a = list(map(int, input().split()))
b = list(range(1, n+1))

a.sort()

if sum(a) != sum(b):
    print(-1)
    exit()

ans = sum(max(0, a[i] - b[i]) for i in range(n))
print(ans)