n = int(input())
for i in range(33, 0, -1):
    # print(i)
    now = 0
    j = 1
    s = ''
    while now <= n:
        now += j ** i
        if s != '':
            s += '+'
        s += f'{j}^{i}'
        if now == n:
            print(s)
            exit()
        elif now > n:
            break
        j += 1
print(f'Impossible for {n}.')