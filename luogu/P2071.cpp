/*
 * Filename: i:\code\cpp\contest\240908-ccpc-online-1\P2071.cpp
 * Path: i:\code\cpp\contest\240908-ccpc-online-1
 * Created Date: Wednesday, September 11th 2024, 8:42:35 pm
 * Author: Glerium
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
int n,head[maxn],cur[maxn],ct,s,t,d[maxn];
struct Edge{
    int to, nxt;
    int cap;
}a[maxn];
int add(int x, int y, int w) {
    // cout<<"add " << x << ' ' << y << ' ' << w << endl;
    a[ct] = {y, head[x], w};
    head[x] = ct++;
    a[ct] = {x, head[y], 0};
    head[y] = ct++;
    return ct - 2;
}
bool dinic_bfs() {
    memset(d, 0, sizeof(d));
    d[s] = 1;
    queue<int> q; 
    q.push(s);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int i=head[now];~i;i=a[i].nxt) {
            int v = a[i].to;
            if(!a[i].cap) continue;
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
    if(u == t)
        return lim;
    int ret = 0;
    for(int &i=cur[u];~i;i=a[i].nxt) {
        if(!a[i].cap) continue;
        int v = a[i].to;
        if(d[v] != d[u] + 1)
            continue;
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
        memcpy(cur, head, sizeof(head));
        int now = dinic_dfs(s, 0x3f3f3f3f);
        ans += now;
    }
    return ans;
}
void solve() {
    cin >> n;
    memset(head, -1, sizeof(head));
    s = 1; t = 3*n+2;
    vector<int> tmp;
    for(int i=1;i<=2*n;i++)
        add(1, i+1, 1);
    for(int i=1;i<=2*n;i++) {
        int x,y; cin>>x>>y;
        add(i+1, x+2*n+1, 1);
        if(x != y)
            add(i+1, y+2*n+1, 1);
    }
    for(int i=1;i<=n;i++)
        add(i+2*n+1, 3*n+2, 2);
    cout << dinic() << endl;
    // for(auto i : tmp)
    //     cout<<a[i].cap<<' ' ;
    // cout<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
