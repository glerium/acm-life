s = input()
a = []
for i, ch in enumerate(s):
    if ch == '#':
        a.append(i + 1)
for i in range(0, len(a), 2):
    print(f'{a[i]},{a[i+1]}')
