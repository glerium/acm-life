/*
 * Filename: i:\code\cpp\contest\240908-ccpc-online-1\P1345.cpp
 * Path: i:\code\cpp\contest\240908-ccpc-online-1
 * Created Date: Thursday, September 12th 2024, 11:14:47 am
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
int n,m,s,t,head[maxn],cur[maxn],ct,d[maxn];
struct Edge{
    int to,nxt; 
    int cap;
}a[maxn];

void add(int x, int y, int c) {
    // cout << "add " << x << ' ' << y << ' ' << c << endl;
    a[ct] = {y, head[x], c};
    head[x] = ct++;
    a[ct] = {x, head[y], 0};
    head[y] = ct++;
}

bool dinic_bfs(){
    memset(d, 0, sizeof(d));
    d[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int i=head[now];~i;i=a[i].nxt) {
            if(!a[i].cap) continue;
            int v = a[i].to;
            if(d[v]) continue;
            d[v] = d[now] + 1;
            q.push(v);
            if(v == t)
                return true;
        }
    }
    return false;
}

int dinic_dfs(int u, int lim) {
    if(u == t) return lim;
    int ret = 0;
    for(int &i=cur[u];~i;i=a[i].nxt) {
        if(!a[i].cap) continue;
        int v = a[i].to;
        if(d[v] != d[u] + 1) continue;
        int tmp = dinic_dfs(v, min(lim - ret, a[i].cap));
        a[i].cap -= tmp;
        a[i^1].cap += tmp;
        ret += tmp;
        if(ret == lim)
            break;
    }
    return ret;
}

int dinic() {
    int ans = 0;
    while(dinic_bfs()) {
        memcpy(cur, head, sizeof(cur));
        int now = dinic_dfs(s, 0x3f3f3f3f);
        ans += now;
    }
    return ans;
}

void solve() {
    int c1, c2;
    cin >> n >> m >> c1 >> c2;
    s = c1 * 2 - 1, t = c2 * 2;
    memset(head, -1, sizeof(head));
    // cow i: 2*i-1, 2*i
    for(int i=1;i<=n;i++) {
        if(i == c1 || i == c2)
            add(2*i-1, 2*i, 100000);
        else
            add(2*i-1, 2*i, 1);
    }
    for(int i=1;i<=m;i++) {
        int x, y; cin >> x >> y;
        add(2*x, 2*y-1, 100000);
        add(2*y, 2*x-1, 100000);
    }
    // cout << s << ' ' << t <<endl;
    cout << dinic() << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
