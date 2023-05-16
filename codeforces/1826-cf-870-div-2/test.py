with open('test.in','w') as f:
    f.write('1\n')
    f.write('100000\n')
    for i in range(100000):
        f.write('1 ')
    f.write('\n')