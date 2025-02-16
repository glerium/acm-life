from collections import Counter

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    counter = list(Counter(a).items())
    # print(counter)
    if len(counter) == 2 and counter[0][1] == counter[1][1]:
        print('Yes')
    else:
        print("No")