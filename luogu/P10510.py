v, q = list(map(int, input().split()))

def con(x):
    s = []
    while x:
        s.append(x % 3)
        x //= 3
    return s

def getans(v):
    ans = 0
    v = v[::-1]
    for i in v:
        ans = ans * 3 + i
    return ans

v = con(v)
while len(v) < 100:
    v.append(0)

for _ in range(q):
    op, i = list(map(int, input().split()))
    if op == 1:
        v[i] = (v[i] + 1) % 3
    elif op == 2:
        v[i] = (v[i] + 2) % 3
    else:
        v[i] = (3 - v[i]) % 3
    print(getans(v))
