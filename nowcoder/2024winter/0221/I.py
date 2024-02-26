t,a,k = list(map(int,input().split()))
if (t>=0 and a>=0) or (t<=0 and a<=0):
    t = abs(t)
    a = abs(a)
    if t > a:
        print(t)
    else:
        print(a + abs(t-a))
else:
    if abs(a) <= k:
        print(abs(a)*2 + abs(t))
    else:
        print(abs(t)*3 + abs(a)*2)