import sys
import threading
sys.setrecursionlimit(1000000)
# threading.stack_size(1024*1024*128)

n,m = map(int,input().split())
c = [0] + list(map(int,input().split()))

a = []
for i in range(n+5):
    a.append([])

for _ in range(m):
    x, y = map(int,input().split())
    if x == y:
        exit()
    a[x].append(y)
    a[y].append(x)

nd = []
cn = [-1] * (n+5)
result = True
def dfs(u: int) -> bool:
    # print(u)
    global nd
    nd.append(u)
    for v in a[u]:
        if cn[v] == -1:
            cn[v] = 1 - cn[u]
            dfs(v)
        elif cn[v] == cn[u]:
            # print(u, v)
            global result
            result = False

ans = 0
for i in range(1, n+1):
    if cn[i] == -1:
        nd.clear()
        cn[i] = 0
        dfs(i)
        if not result:
            print('Impossible')
            exit()
        cur = sum(abs(c[i] - cn[i]) for i in nd)
        for node in nd:
            cn[node] = -1

        nd = []
        cn[i] = 1
        dfs(i)
        if not result:
            print('Impossible')
            exit()
        cur = min(cur, sum(abs(c[i] - cn[i]) for i in nd))
        ans += cur

print(ans)
