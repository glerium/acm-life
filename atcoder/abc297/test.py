from typing import Callable

class Factorial():
    def __init__(self, max_n: int, mod: Callable[[], int]) -> None:
        self._mod = mod
        self._fact = [0] * (max_n + 1)
        self._invf = [0] * (max_n + 1)
        self._inv = [0] * (max_n + 1)
        self._fact[0] = self._fact[1] = 1
        self._invf[0] = self._invf[1] = 1
        self._inv[1] = 1
        for i in range(2, max_n + 1):
            self._fact[i] = self._fact[i - 1] * i % mod()
            self._inv[i] = -self._inv[mod() % i] * (mod() // i) % mod()
            self._invf[i] = self._invf[i - 1] * self._inv[i] % mod()

    def comb(self, n: int, k: int) -> int:
        assert 0 <= n and 0 <= k
        if n < k: return 0
        return self._fact[n] * self._invf[k] % self._mod() * self._invf[n - k] % self._mod()
    
    
MOD = lambda: 998244353

H, W, K = map(int, input().split())

F = Factorial(H * W + 1, MOD)

res = 0

for i in range(H):
    for j in range(W):
        tmp = 0
        tmp += F.comb(H * W, K)
        tmp -= F.comb(i * W, K)
        tmp -= F.comb((H - i - 1) * W, K)
        tmp -= F.comb(j * H, K)
        tmp -= F.comb((W - j - 1) * H, K)
        tmp += F.comb(i * j, K)
        tmp += F.comb(i * (W - j - 1), K)
        tmp += F.comb((H - i - 1) * j, K)
        tmp += F.comb((H - i - 1) * (W - j - 1), K)
        res += tmp % MOD()
        res %= MOD()

res *= pow(F.comb(H * W, K), MOD() - 2, MOD())
res %= MOD()

print(res)
