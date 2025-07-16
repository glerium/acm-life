mod = 998244353

n = int(input())
ans = n * (n - 1) // 2 % mod
curbegin = 1
while curbegin <= n:
    curct = n // curbegin
    curend = n // curct
    len = curend - curbegin + 1
    ans -= (curct - 1) * len % mod
    ans %= mod
    curbegin = curend + 1
ans %= mod
print(ans)
