n, m = map(int, input().split())
a = [[0]]
for i in range(1, n+1):
    line = list(map(int, input().split()))
    a.append([0] + line)
ans = 0

for i in range(1, n + 1):
    b = a[i]
    f = [[-1] * (m + 1) for _ in range(m + 1)]
    # f[l][r]: max score with [l, r] exist
    f[1][m] = 0
    
    def dp(l: int, r: int) -> int:
        if f[l][r] != -1:
            return f[l][r]
        i = m - (r - l + 1)
        if r + 1 <= m:
            f[l][r] = max(f[l][r], dp(l, r + 1) + b[r + 1] * (1 << i))
        if l - 1 >= 1:
            f[l][r] = max(f[l][r], dp(l - 1, r) + b[l - 1] * (1 << i))
        return f[l][r]

    nowAns = 0
    for j in range(m + 1):
        nowAns = max(nowAns, dp(j, j) + b[j] * (1 << m))
    ans += nowAns

print(ans)
