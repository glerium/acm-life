/*
 * Filename: i:\code\cpp\codeforces\gym-104976-hangzhou-2023\G2.cpp
 * Path: i:\code\cpp\codeforces\gym-104976-hangzhou-2023
 * Created Date: Thursday, October 3rd 2024, 9:32:36 pm
 * Author: Glerium
 * 
 * Copyright (c) 2024  
 */

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
constexpr int maxn = 3e3+10;
constexpr int maxm = 1e7+10;
constexpr int to[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
constexpr int inf = 0x3f3f3f3f3f3f3f3f;
int n,m,k;
int snk[maxn][maxn], sx[100010], sy[100010];
string mp[maxn];

int head[maxm];
struct Edge {
    int to, nxt;
}a[maxm << 2];
bool v[maxm];
int ct = 0;

struct State {
    int x;
    int step;
    bool operator<(const State& rhs)const {
        return step > rhs.step;
    }
};
int step[maxm];

inline int p(int x, int y) {
    return (x-1)*m+y-1;
}
pair<int,int> dc(int x) {
    return make_pair(x/m+1, x%m+1);
}

void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i=1,x,y;i<=k;i++) {
        cin >> x >> y;
        sx[i] = x; sy[i] = y;
        snk[x][y] = i;
    }
    for(int i=1;i<=n;i++) {
        cin >> mp[i];
        mp[i] = ' ' + mp[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(mp[i][j] == '#')
                continue;
            if(i-1 >= 1 && mp[i-1][j] != '#') {
                add(p(i,j), p(i-1,j));
            }
            if(i+1 <= n && mp[i+1][j] != '#') {
                add(p(i,j), p(i+1,j));
            }
            if(j-1 >= 1 && mp[i][j-1] != '#') {
                add(p(i,j), p(i,j-1));
            }
            if(j+1 <= m && mp[i][j+1] != '#') {
                add(p(i,j), p(i,j+1));
            }
        }
    }
    
    priority_queue<State> q;
    q.push({p(sx[1], sy[1]), 0});
    memset(step, 0x3f, sizeof(step));
    step[p(sx[1], sy[1])] = 0;
    while(!q.empty()) {
        auto now = q.top(); q.pop();
        if(v[now.x]) continue;
        v[now.x] = true;
        if(now.step != step[now.x])     // removed state
            continue;
        auto dcr = dc(now.x);
        int x = dcr.first, y = dcr.second;
        for(int i=0;i<4;i++) {
            int tx = x + to[i][0],
                ty = y + to[i][1];
            if(mp[tx][ty] == '#')
                continue;
            if(tx < 1 || tx > n || ty < 1 || ty > m)
                continue;               // illegal
            int tp = p(tx, ty);
            int next_step = now.step + 1;
            if(snk[tx][ty]) next_step = max(next_step, k - snk[tx][ty] + 1);
            if(next_step < step[tp]) {
                step[tp] = next_step;
                q.push({tp, next_step});
            }
        }
    }
    
    unsigned long long ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(step[p(i,j)] == inf)
                step[p(i,j)] = 0;
            // cout << step[p(i,j)] << ' ';
            ans += 1ull * step[p(i,j)] * step[p(i,j)];
        }
        // cout << endl;
    }
    cout << ans << endl;
}