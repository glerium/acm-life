n = int(input())
l, r = list(map(int,input().split()))

def sqrtint(x: int) -> int:
    l, r = 0, x
    ans = -1
    while l <= r:
        mid = (l + r) // 2
        if mid * mid <= x:
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    return ans

def solve(x: int) -> int:
    x = str(x)
    x = '0' * (n - len(x)) + x
    left = int(x[:n//2])
    right = int(x[n//2:])
    ans = 0
    tmp = sqrtint(left)
    if tmp * tmp == left:
        ans = (tmp - 1) * (sqrtint(10 ** (n // 2) - 1) + 1)
        ans += sqrtint(right) + 1
    else:
        ans = tmp * (sqrtint(10 ** (n // 2) - 1) + 1)
    return ans

# def solve2(x: int) -> int:
#     begin = 10 ** (n // 2)
#     ans = 0
#     for i in range(begin, x + 1):
#         ii = str(i)
#         ii = '0' * (n - len(ii)) + ii
#         left = int(ii[:n//2])
#         right = int(ii[n//2:])
#         tmp = sqrtint(left)
#         tmp2 = sqrtint(right)
#         if tmp * tmp == left and tmp2 * tmp2 == right:
#             ans += 1
#     return ans

# for i in range(1000, 10000):
#     if i % 100 == 0:
#         print(f'ok {i}')
#     if solve(i) != solve2(i):
#         print(i, solve(i), solve2(i))

print(solve(r) - solve(l - 1))
