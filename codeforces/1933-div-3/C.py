import math
t = int(input())
for _ in range(t):
    a, b, l = list(map(int,input().split()))
    la = int(math.log(l, a))
    lb = int(math.log(l, b))
    st = set()
    for i in range(la + 2):
        for j in range(lb + 2):
            now = a ** i * b ** j
            if l % now == 0:
                st.add(l / now)
    print(len(st))
