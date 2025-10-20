import random
t = 1
f = open('in.txt', 'w')
f.write(str(t) + '\n')
for tc in range(t):
    n = 10000
    f.write(str(n) + '\n')
    a = [random.randint(1, 8) for i in range(n)]
    f.write(' '.join(map(str, a)) + '\n')
f.close()
