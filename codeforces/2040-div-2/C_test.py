from math import inf
from itertools import permutations

n,k = map(int,input().split())
a = range(1, n+1)
mp = {}
for p in permutations(a):
    ans = 0
    for l in range(n):
        for r in range(l, n):
            ans += min(p[l : r+1])
    # print(ans)
    if ans not in mp:
        mp[ans] = []
    mp[ans].append(p)
ps = mp[max(mp.keys())]
print(ps[k-1])
