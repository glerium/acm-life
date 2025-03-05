from collections import Counter

n, q = map(int, input().split())

s = input()
for _ in range(q):
    l, r = map(int, input().split())
    ss = s[l-1 : r]
    counter = Counter(ss)
    ok = False
    # print(counter)
    for k, v in counter.items():
        if v == 1:
            ok = True
    print('YES' if ok else 'NO')
