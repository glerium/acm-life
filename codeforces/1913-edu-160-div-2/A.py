t = int(input())
for _ in range(t):
    n = input()
    ok = False
    for i in range(1, len(n)):
        a = n[:i]
        b = n[i:]
        if b[0] == '0':
            continue
        a = int(a)
        b = int(b)
        if b > a:
            print(a,b)
            ok = True
            break
    if not ok:
        print(-1)