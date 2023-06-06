try:
    while True:
        s = input()
        if(s == ''):
            break
        n,m=map(int,s.split(' '))
        f=[[0 for j in range(105)] for i in range(105)]
        for i in range(1,n+1):
            f[i][1]=1
        for i in range(1,n+1):
            for j in range(2,m+1):
                f[i][j]=f[i-1][j-1]+f[i-1][j]*j
        print(f[n][m])
except EOFError:
    pass