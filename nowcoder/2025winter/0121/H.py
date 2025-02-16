n = int(input())
a = []
for i in range(n):
    x, y = map(int,input().split())
    a.append((x, y, i+1))
a.sort(key=lambda i: (i[0], i[1]))
for z, (x, y, _) in enumerate(a, start=1):
    if not (x <= z <= y):
        print(-1)
        exit()
for _, _, z in a:
    print(z, end=' ')

'''
1 2
2 3
1 3
'''
