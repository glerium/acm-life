n,x = list(map(int,input().split()))
if (n - x) % 2 != 0 or n < x:
    print(-1)
    exit(0)
print((n+x)//2, (n-x)//2)