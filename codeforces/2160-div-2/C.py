t = int(input())
for _ in range(t):
    n = int(input())
    n = bin(n)[2:]
    ok = False
    for i in range(100):
        s = '0' * i + n
        if s == s[::-1]:
            if len(s) % 2 == 1 and s[len(s) // 2] == '1':
                continue
            ok = True
            break
    if ok:
        print("YES")
    else:
        print("NO")
