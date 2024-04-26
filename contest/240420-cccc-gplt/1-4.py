n = int(input())
words = []
for _ in range(n):
    words.append(input())
k = int(input())
s = input()
start = 0
count = 0
i = 0
while i < len(s):
    s = []
    for word in words:
        if i + len(word) > len(s):
            continue
        if s[i:i+len(word)] == word:
            count += 1
            s = s[:i] + '<censored>' + s[i+len(word):]
            i += len('<censored>') - 1
            break
    i += 1
if count >= k:
    print(count)
    print('He Xie Ni Quan Jia!')
else:
    print(s)