'''
Filename: i:\code\cpp\codeforces\gym-104976-hangzhou-2023\M.py
Path: i:\code\cpp\codeforces\gym-104976-hangzhou-2023
Created Date: Thursday, October 3rd 2024, 1:19:29 pm
Author: 温泽林

Copyright (c) 2024  
'''

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    avg = sum(a) / len(a)
    ans = avg
    lowest = -1
    for idx, i in enumerate(a):
        if a[idx-1] > i and i < a[idx+1]:
            lowest = idx
            break
        
    ss = 0
    ct = 0
    for idx in range(lowest - 1):
        ss += a[idx]
        ct += 1
        ans = max(ans, (avg * len(a) - ss) / (len(a) - ct))
    
    ss = 0
    ct = 0
    for idx in range(len(a) - 1, lowest + 1, -1):
        ss += a[idx]
        ct += 1
        ans = max(ans, (avg * len(a) - ss) / (len(a) - ct))
    print(ans)
