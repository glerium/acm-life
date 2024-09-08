n = input()
n_ = int(n, 2)
n_ *= 21
s = ''
while n_:
    s += '1' if n_ % 2 else '0'
    n_ //= 2
s = s[::-1]
print(s)