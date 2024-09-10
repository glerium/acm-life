/*
 * Filename: i:\code\cpp\luogu\P3376.cpp
 * Path: i:\code\cpp\luogu
 * Created Date: Tuesday, September 10th 2024, 4:39:54 pm
 * Author: 温泽林
 * 
 * Copyright (c) 2024  
 */

#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
int n,m,s,t,level[205];
struct DinicEdge {
    ll c, f;
} a[205][205];

bool dinic_bfs() {
    memset(level, 0, sizeof(level));
    level[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int i=1;i<=n;i++) {
            if(level[i]) continue;
            if(a[now][i].c <= a[now][i].f) continue;
            level[i] = level[now] + 1;
            if(i == t)
                return true;
            q.push(i);
        }
    }
    return false;
}

ll dinic_dfs(int x, ll lim) {
    if(x == t) return lim;
    ll ret = 0;
    for(int i=1; i<=n&&lim>0; i++) {
        if(level[i] != level[x] + 1)
            continue;
        ll cur = dinic_dfs(i, min(lim, a[x][i].c - a[x][i].f));
        a[x][i].f += cur;
        a[i][x].f -= cur;
        lim -= cur;
        ret += cur;
    }
    return ret;
}

ll dinic() {
    ll ans = 0;
    while(dinic_bfs()) {
        ll tmp = dinic_dfs(s, 0x3f3f3f3f3f3f3f3f);
        ans += tmp;
    }
    return ans;
}

void solve() {
    cin >> n >> m >> s >> t;
    for(int i=1;i<=m;i++) {
        int x,y;
        ll z;
        cin>>x>>y>>z;
        a[x][y].c += z;
    }
    cout << dinic() << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
