n, q = map(int, input().split())

s = input()

c = [[0] * 26] * (n+5)
for idx, i in enumerate(s):
    if idx > 0:
        c[idx] = c[idx - 1].copy()
    c[idx][ord(i) - ord('a')] += 1


for _ in range(q):
    l, r = map(int, input().split())
    l -= 1
    r -= 1
    ok = False
    if l == 0:
        for i in range(26):
            if c[r][i] == 1:
                ok = True
    else:
        for i in range(26):
            if c[r][i] - c[l-1][i] == 1:
                ok = True
    print('YES' if ok else 'NO')
