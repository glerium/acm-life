from random import Random
rnd = Random()

n = 20
a = list(range(1, n+1))
rnd.shuffle(a)

print(a)
print(n)
for i in a:
    l = r = 0
    while not l <= i <= r:
        l = rnd.randint(1, n)
        r = rnd.randint(l, n)
    print(l, r)