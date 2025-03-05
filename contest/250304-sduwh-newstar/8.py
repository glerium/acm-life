from itertools import permutations

class Problem:
    def __init__(self, s, d, f, id):
        self.s = s
        self.d = d
        self.f = f
        self.id = id

t = int(input())

for _ in range(t):
    n = int(input())
    s = list(map(int, input().split()))
    d = list(map(int, input().split()))
    f = list(map(int, input().split()))
    p = []
    for idx, i in enumerate(range(n)):
        p.append(Problem(s[idx], d[idx], f[idx], chr(ord('A') + idx)))
    
    ans = (0, None)
    for pb in permutations(p, r=n):
        now = 0
        curr = 0
        order = ''
        for problem in pb:
            problem: Problem
            now += problem.d
            curr += max(problem.s * 3 // 10, problem.s - now * problem.s // 250 - problem.f * 50)
            order += problem.id
        if curr > ans[0]:
            ans = (curr, order)
    print(ans[0], ans[1])
