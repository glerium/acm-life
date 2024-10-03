/*
 * Filename: i:\code\cpp\codeforces\gym-104976-hangzhou-2023\J.cpp
 * Path: i:\code\cpp\codeforces\gym-104976-hangzhou-2023
 * Created Date: Thursday, October 3rd 2024, 1:41:08 pm
 * Author: 温泽林
 * 
 * Copyright (c) 2024  
 */

#include <bits/stdc++.h>
using namespace std;
int ask(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int resp;
    scanf("%d", &resp);
    return resp;
}
void answer(int x) {
    printf("! %d\n", x);
    fflush(stdout);
}
void solve() {
    int n; cin >> n;
    int x=-1, y=-1;
    for(int i=1;i+1<=n;i+=2) {
        int resp = ask(i, i+1);
        if(resp) {
            x = i;
            y = i+1;
            break;
        }
    }
    if(n&1) {
        int resp = ask(n, n-1);
        if(resp) {
            x = n;
            y = n-1;
        }
    }
    if(x == -1 && y == -1) {
        answer(1);      // chain
        return;
    }
    int tx, ty;
    {
        set<int> st = {1, 2, 3, 4};
        if(st.count(x)) st.erase(x);
        if(st.count(y)) st.erase(y);
        tx = *st.begin();
        ty = *++st.begin();
    }
    int resp = ask(x, tx);
    if(resp) {
        resp = ask(x, ty);
        if(resp) {
            answer(2);  // star: x1, xn
        } else {
            answer(1);  // chain: x1, !xn
        }
    } else {
        resp = ask(y, tx);
        if(resp) {
            resp = ask(y, ty);
            if(resp) {
                answer(2);  // star: y1, yn
            } else {
                answer(1);  // chain: y1, !yn
            }
        } else {
            answer(1);  // chain: !x1, !y1
        }
    }
}
int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}