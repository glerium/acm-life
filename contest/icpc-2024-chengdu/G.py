n = int(input())
a = list(map(int, input().split()))

st = a

for _ in range(10000):
    for i in range(len(a) - 1):
        if (a[i] ^ a[i+1]) not in st:
            a.insert(i+1, a[i] ^ a[i+1])
        if (a[i] & a[i+1]) not in st:
            a.insert(i+1, a[i] & a[i+1])
        if (a[i] | a[i+1]) not in st:
            a.insert(i+1, a[i] | a[i+1])
a = [0] + a
print(a)
print(len(st))
