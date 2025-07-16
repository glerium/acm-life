import random

n = 5
for _ in range(10000):
    a = []
    for i in range(n):
        a.append(random.randint(1, 5))
    # print(a)
    d = {}
    ans1 = min(a) + max(a)
    for i in range(1, 1<<n):
        mi = 114514
        mx = -114514
        for j in range(n):
            if (1<<j) & i:
                mi = min(mi, a[j])
                mx = max(mx, a[j])
        if mi+mx not in d:
            d[mi+mx] = 0
        d[mi+mx] += 1
    ans2 = 0
    anst = max(d.values())
    # print(d)
    # exit()
    for k, v in sorted(d.items()):
        if v == anst:
            ans2 = k
    ct = {}
    for i in range(a):
        ct[i] += 1
    if ans1 != ans2:
        print('Found!')
        print(n)
        print(a)
        print(ans1, ans2)