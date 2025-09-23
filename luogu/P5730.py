n = int(input())
s = input()

scr = ['XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX',
       'X.X...X...X...X.X.X.X...X.....X.X.X.X.X',
       'X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX',
       'X.X...X.X.....X...X...X.X.X...X.X.X...X',
       'XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX']

# i: [0, 4n] -> [4, 4n + 2]
out = [""] * 5
for i in range(5):
    for j in range(n):
        od = ord(s[j]) - ord('0')
        out[i] += scr[i][4 * od : 4 * od + 3]
        if j != n - 1:
            out[i] += '.'
    print(out[i])
