t = int(input())
for _ in range(t):
    n = int(input())
    l = 1
    r = n
    while l < r:
        print(f'{l} {r} ', end='')
        l+=1
        r-=1
    if n % 2 == 1:
        print(f'{l} ', end='')
    print()