n, m = map(int, input().split())
s = input()

# mp = {ch: idx for idx, ch in enumerate(s)}

ct = len(s) ** m
# assert(ct <= 1e9)

length = ct // n
ranges = []
x = 0
for i in range(n):
    if i < ct % n:
        leng = length + 1
    else:
        leng = length
    ranges.append((x, x + leng - 1))
    x += leng
# ranges = [(length * i, min(length*(i+1)-1, ct - 1)) for i in range(n)]

# print(ct)
# print([y - x for x, y in ranges])

def to_base(x: int):
    ret = ''
    while x:
        md = x % len(s)
        ret += s[md]
        x //= len(s)
    ret = ret[::-1]
    ret = s[0] * (m - len(ret)) + ret
    return ret


for rl, rr in ranges:
    rl = to_base(rl)
    rr = to_base(rr)
    print(rl, rr)
