a,b=list(map(int,input().split()))
mx = 0
ct = {}
def getans(x):
    ans = 0
    while x >= 10:
        x = list(map(ord, list(str(x))))
        x = [i - ord('0') for i in x]
        kk = 1
        for i in x:
            kk *= i
        x = kk
        ans += 1
    return ans
for i in range(a, b+1):
    ans = getans(i)
    mx = max(ans, mx)
    if ans not in ct:
        ct[ans] = [i]
    else:
        ct[ans].append(i)
print(mx)
print(' '.join(list(map(str,ct[mx]))))
