from collections import Counter

n = int(input())
a = []
for _ in range(n-1):
    a.extend(map(int, input().split()))
counter = Counter(a)
ans = []
for k, v in counter.items():
    if v > 2:
        print(-1)
    elif v == 1:
        ans.append(k)
print(' '.join(map(str, ans)))