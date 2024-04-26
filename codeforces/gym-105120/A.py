t = int(input())
for _ in range(t):
    k = int(input())
    ta, fa = list(map(int, input().split()))
    tb, fb = list(map(int, input().split()))
    if ta == tb:
        print(abs(fa - fb))
    else:
        small = fa // k * k
        big = small + k
        ans = min(abs(fa - small) + abs(fb - small), abs(fa - big) + abs(fb - big)) + 3
        print(ans)