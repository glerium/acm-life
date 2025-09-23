x,y = map(int,input().split())
f = [0] * 15
f[1] = x
f[2] = y

def func(x):
    return int(str(x)[::-1])

for i in range(3, 11):
    f[i] = func(f[i-1] + f[i-2])

print(f[10])
