t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ct_one = sum([i == 1 for i in a])
    if n == ct_one:
        if n % 2 == 1:
            print("Cxlian")
        else:
            print("Student")
    elif ct_one % 2 == 0:
        print("Cxlian")
    else:
        print('Student')
