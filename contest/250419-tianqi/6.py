n,m = map(int,input().split())
s = list(map(int,input().split()))

def transform(a: list):
    return ''.join([chr(ord('a') + i - 1) for i in a])

s = transform(s)
for _  in range(m):
    # print('now:')
    # final_a = [ord(i) - ord('a') + 1 for i in s]
    # print(' '.join(map(str, final_a)))
    op = int(input())
    if op == 1:
        tmp = list(map(int, input().split()))
        l1 = tmp[0]
        a = transform(tmp[1:])
        tmp = list(map(int, input().split()))
        l2 = tmp[0]
        b = transform(tmp[1:])
        s = s.replace(a, b, 1)
    elif op == 2:
        ns = ''
        for i in range(0, len(s) - 1):
            ns += s[i]
            if (ord(s[i]) + ord(s[i+1])) % 2 == 0:
                ns += chr((ord(s[i]) + ord(s[i+1])) // 2)
        ns += s[-1]
        s = ns
    else:
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        s = s[:l] + s[r:(l-1 if l-1 >= 0 else None):-1] + s[r+1:]
    
final_a = [ord(i) - ord('a') + 1 for i in s]
print(' '.join(map(str, final_a)))
