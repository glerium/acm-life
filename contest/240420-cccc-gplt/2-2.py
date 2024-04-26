n = int(input())
sdict = {}
for i in range(n):
    s = input()
    beg = ''.join([i[0] for i in s.split()])
    if beg not in sdict:
        sdict[beg] = set()
    sdict[beg].add(s)
q = int(input())
for _ in range(q):
    s = input()
    beg = ''.join([i[0] for i in s.split()])
    if beg not in sdict:
        print(s)
    else:
        ans = list(sdict[beg])
        ans.sort()
        print('|'.join(ans))