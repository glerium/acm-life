n = int(input())
s = []
for i in range(n):
    s.append(input())
t = input()
m = len(t)
i = 0
while i < m:
    fnd = -1
    for j in range(n):
        if t[i : i + len(s[j])] == s[j]:
            if fnd == -1 or len(s[fnd]) < len(s[j]):
                fnd = j
    if fnd != -1:
        t = t[:i] + '*' * len(s[fnd]) + t[i + len(s[fnd]):]
        i += len(s[fnd])
    else:
        i += 1
print(t)
