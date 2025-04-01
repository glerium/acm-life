def check(ct):
    return ct[0] >= 3 and ct[1] >= 1 and ct[2] >= 2 and ct[3] >= 1 and ct[5] >= 1

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ct = [0] * 10
    ans = 0
    for idx, ch in enumerate(a, start=1):
        ct[ch] += 1
        if check(ct):
            ans = idx
            break
    print(ans)