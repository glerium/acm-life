n = int(input())
a = []
for _ in range(n):
    a.append(input())
    a.sort(key=lambda x: (len(x)))
print(''.join(a))