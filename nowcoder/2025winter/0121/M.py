n = int(input())
a = list(map(int, input().split()))

a.sort()
a[0] *= 2
a.sort()
print(a[-1] - a[0])