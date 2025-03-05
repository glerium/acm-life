n = int(input())
a = map(int, input().split())

x = 0
for i in a:
    print(x + (i - x) / 4, end=' ')
    x = round(x + (i - x) / 4)
