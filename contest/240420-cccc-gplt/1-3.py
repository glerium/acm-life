a, b = list(map(int, input().split()))
if b == 0:
    if a == 0:
        print('biii')
    elif a == 1:
        print('dudu')
    else:
        print('-')
else:
    print('-')

if a == 0 or a == 2:
    print('stop')
else:
    print('move')