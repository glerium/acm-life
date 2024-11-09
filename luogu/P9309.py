a, b = map(int, input().split())

def getans(x):
    two = [0] * 100
    five = [0] * 100
    for i in range(1, 100):
        if 2 ** i > x:
            break
        two[i] = x // 2 ** i
    for i in range(1, 100):
        if 5 ** i > x:
            break
        five[i] = x // 5 ** i
    return two, five

two1, five1 = getans(b)
two2, five2 = getans(a-1)

two = []
five = []
for i in range(len(two1)):
    two.append(two1[i] - two2[i])
    five.append(five1[i] - five2[i])
ans1 = ans2 = 0
for i in range(len(two)):
    if two[i] > 0:
        ans1 = i
for i in range(len(five)):
    if five[i] > 0:
        ans2 = i
print(min(ans1, ans2))