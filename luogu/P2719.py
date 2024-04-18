from decimal import Decimal, getcontext

n = int(input())
n *= 2
getcontext().prec = 500
ans = Decimal("2.0")
for i in range(1, n):
    ans = ans * (i+n-1) / i / Decimal("4.0")
print(f"{1-ans:.4f}")
# print(ans)