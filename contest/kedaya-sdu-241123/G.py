l, r = map(int,input().split())
ans = (l+r)*(r-l+1)//2
if l == 1:
    ans += 1
print(ans)
