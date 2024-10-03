tt = [-1, 0, 1]

for i1 in tt:
    for i2 in tt:
        for i3 in tt:
            for i4 in tt:
                print(i4, i3, i2, i1, i1 + i2*2 + i3*4 + i4*8, sep='\t')