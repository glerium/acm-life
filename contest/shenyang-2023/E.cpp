/*
 * Filename: i:\code\cpp\contest\shenyang-2023\E.cpp
 * Path: i:\code\cpp\contest\shenyang-2023
 * Created Date: Saturday, October 5th 2024, 1:21:42 pm
 * Author: 温泽林
 * 
 * Copyright (c) 2024  
 */

#include <bits/stdc++.h>
using namespace std;
struct State {
    int as, aw, bs, bw;
    bool a;
    int step;
    bool operator<(const State& rhs)const{
        return step > rhs.step;
    }
};
map<int, int> step;

int enc(int as, int aw, int bs, int bw, bool a) {
    return a * 100000001 + as * 1000001 + aw * 100001 + bs * 101 + bw;
}
int main() {
    ios::sync_with_stdio(false);
    int x, y, p, q; cin >> x >> y >> p >> q;
    priority_queue<State> que;
    que.push({x, y, 0, 0, true, 0});
    step[enc(x, y, 0, 0, true)] = 0;
    while(!que.empty()) {
        auto now = que.top(); que.pop();
        // cout << now.as << ' ' << now.aw << ' ' << now.bs << ' ' << now.bw << ' ' << now.a << ' ' << now.step << endl;
        if(now.bs == x) {
            cout << now.step << endl;
            return 0;
        }
        if(now.step != step[enc(now.as, now.aw, now.bs, now.bw, now.a)])
            continue;
        if(now.a) {
            for(int i=0;i<=min(p, now.as); i++) {
                for(int j=0;j<=min(p, now.aw) && i+j<=p; j++) {
                    State nxt = {now.as-i, now.aw-j, now.bs+i, now.bw+j, !now.a, now.step+1};
                    if(step.count(enc(nxt.as, nxt.aw, nxt.bs, nxt.bw, nxt.a)))
                        continue;
                    if(nxt.aw > nxt.as + q && nxt.as) continue;
                    if(nxt.as < 0 || nxt.aw < 0) continue;
                    step[enc(nxt.as, nxt.aw, nxt.bs, nxt.bw, nxt.a)] = nxt.step;
                    que.push({nxt.as, nxt.aw, nxt.bs, nxt.bw, nxt.a, nxt.step});
                }
            }
        } else {
            for(int i=0;i<=min(p, now.bs); i++) {
                for(int j=0;j<=min(p, now.bw) && i+j<=p; j++) {
                    State nxt = {now.as+i, now.aw+j, now.bs-i, now.bw-j, !now.a, now.step+1};
                    if(step.count(enc(nxt.as, nxt.aw, nxt.bs, nxt.bw, nxt.a)))
                        continue;
                    if(nxt.bw > nxt.bs + q && nxt.bs) continue;
                    if(nxt.bs < 0 || nxt.bw < 0) continue;
                    step[enc(nxt.as, nxt.aw, nxt.bs, nxt.bw, nxt.a)] = nxt.step;
                    que.push({nxt.as, nxt.aw, nxt.bs, nxt.bw, nxt.a, nxt.step});
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}