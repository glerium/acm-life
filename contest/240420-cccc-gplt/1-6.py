t = int(input())
for _ in range(t):
    a = []
    for i in range(9):
        row = list(map(int,input().split()))
        a.append(row)
        del row
    ok = True
    correct = set([1,2,3,4,5,6,7,8,9])
    for i in range(9):
        if set([a[i][j] for j in range(9)]) != correct:
            ok = False
    for i in range(9):
        if set([a[j][i] for j in range(9)]) != correct:
            ok = False
    for i in range(0, 9, 3):
        for j in range(0, 9, 3):
            cur = set()
            for x in range(i,i+3):
                for y in range(j,j+3):
                    cur.add(a[x][y])
            if cur != correct:
                ok = False
    print(1 if ok else 0)