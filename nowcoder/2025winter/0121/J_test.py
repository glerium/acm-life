from itertools import combinations, product
from math import gcd

n = 10000
a = range(1, n+1)
# ans = 0
# for x, y in combinations(a, 2):
#     # if len(bin(x)[2:]) == len(bin(y)[2:]):
#         # print(bin(x)[2:], bin(y)[2:])
#     if gcd(x, y) == x ^ y:
#         # ans.add(gcd(x, y))
#         # print(x, y, gcd(x, y), bin(x)[2:], bin(y)[2:], sep='\t')
#         ans += 1
#     # if x * 2 > y and y % (y - x) == 0:
#     #     print(1)
with open('in.txt', 'w') as f:
    f.write(f'{n}\n')
    f.write(' '.join(map(str, a)) + '\n')
# print(ans)
