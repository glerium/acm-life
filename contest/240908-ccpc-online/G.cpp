/*
 * Filename: i:\code\cpp\contest\240908-ccpc-online-1\G.cpp
 * Path: i:\code\cpp\contest\240908-ccpc-online-1
 * Created Date: Tuesday, September 10th 2024, 7:32:37 pm
 * Author: 温泽林
 * 
 * Copyright (c) 2024  
 */

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e4+10;
constexpr ll mod = 998244353;
int n,m,a[maxn],v[maxn],lim[maxn],N,level[maxn],cur[maxn],head[maxn],ct,s,t;
struct Dish{
    int x,y,w;
}d[maxn];
struct Edge{
    int to, nxt;
    int cap;
}p[maxn];
void add(int x,int y,int c){
    p[ct]= {y,head[x],c};
    head[x] = ct++;
    p[ct] = {x,head[y],0};
    head[y] = ct++;
}

bool dinic_bfs() {
    memset(level, 0, sizeof(level));
    level[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int i=head[now];~i;i=p[i].nxt) {
            if(level[p[i].to]) continue;
            if(!p[i].cap) continue;
            level[p[i].to] = level[now] + 1;
            q.push(p[i].to);
            if(p[i].to == t)
                return true;
        }
    }
    return false;
}

int dinic_dfs(int x, int lim) {
    if(x == t)
        return lim;
    int ret = 0;
    for(int &i=cur[x];~i;i=p[i].nxt) {
        int v = p[i].to;
        // cout << "level " << level[x] << " -> " << level[v] << ": " << i << endl;
        if(level[v] != level[x] + 1)
            continue;
        if(!p[i].cap)
            continue;
        int tmp = dinic_dfs(v, min(lim - ret, p[i].cap));
        // cout << "::" << i << ' ' << tmp << endl;
        p[i].cap -= tmp;
        p[i^1].cap += tmp;
        ret += tmp;
        if(ret == lim)
            break;
    }
    // cout << x << ' ' << ret << endl;
    return ret;
}

int dinic() {
    int ans = 0;
    while(dinic_bfs()) {
        memcpy(cur, head, sizeof(cur));
        int now = dinic_dfs(s, 0x3f3f3f3f);
        // for(int i=0;i<ct;i++) {
        //     cout << p[i].cap << ' ';
        // }
        // cout << endl;
        ans += now;
    }
    return ans;
}

void solve() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i] >> v[i];
    for(int i=1;i<=m;i++)
        cin >> d[i].x >> d[i].y >> d[i].w;
    {
        int ss = 0;
        for(int i=1;i<=m;i++) {
            if(d[i].x == 1 || d[i].y == 1)
                ss += d[i].w;
        }
        lim[1] = min(ss, a[1] - v[1]);
    }
    for(int i=2;i<=n;i++) {
        lim[i] = min(lim[1] + v[1] - v[i] - 1, a[i] - v[i]);
        if(lim[i] < 0) {
            cout << "NO" << endl;
            return;
        }
        // cout << lim[i] << endl;
    }
    // start: 1, dishes: 2~m+1, people: m+2~m+n+1, end: m+n+2
    s = 1; t = m + n + 2;
    N = m+n+2;
    for(int i=1;i<=m;i++)
        add(1, i+1, d[i].w);
    for(int i=1;i<=m;i++) {
        add(i+1, d[i].x+m+1, d[i].w);
        if(d[i].x != d[i].y)
            add(i+1, d[i].y+m+1, d[i].w);
    }
    for(int i=1;i<=n;i++)
        add(i+m+1, m+n+2, lim[i]);
    int target = 0;
    for(int i=1;i<=m;i++)
        target += d[i].w;
    // for(int i=1;i<=N;i++) {
    //     for(int j=1;j<=N;j++) {
    //         if(p[i][j].c != 0)
    //             cout << ":" << i << ' ' << j << ' ' << p[i][j].c << endl;
    //     }
    // }
    int real = dinic();
    // cout << real << endl;
    if(real == target)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
