#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 1e4+10;
int n,m,head[maxn],ct,level[maxn],cur[maxn];
int r[107][107],id[107][107],s,t;
constexpr int to[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
struct Edge {
    int to,nxt;
    ll cap;
}a[maxn<<1];
void add(int x, int y, ll w) {
    a[ct] = {y,head[x],w};
    head[x] = ct++;
    a[ct] = {x,head[y],0};
    head[y] = ct++;
}
bool dinic_bfs() {
    memset(level, 0, sizeof(level));
    level[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int i=head[now];~i;i=a[i].nxt) {
            if(level[a[i].to]) continue;
            if(!a[i].cap) continue;
            level[a[i].to] = level[now] + 1;
            q.push(a[i].to);
            if(a[i].to == t) return true;
        }
    }
    return false;
}
ll dinic_dfs(int x, ll lim) {
    if(x == t) return lim;
    ll ret = 0;
    for(int &i=cur[x];~i;i=a[i].nxt) {
        int v=a[i].to;
        if(level[v] != level[x] + 1) continue;
        if(!a[i].cap) continue;
        ll tmp = dinic_dfs(v, min(lim - ret, a[i].cap));
        a[i].cap -= tmp;
        a[i^1].cap += tmp;
        ret += tmp;
        if(ret == lim)
            break;
    }
    return ret;
}
ll dinic() {
    ll ans = 0;
    while(dinic_bfs()) {
        memcpy(cur, head, sizeof(cur));
        ll now = dinic_dfs(s, 0x3f3f3f3f);
        ans += now;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> r[i][j];
        }
    }
    s = n*m+1;
    t = n*m+2;
    // s -> oven -> odd -> t
    {
        int ct = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                id[i][j] = ++ct;
            }
        }
    }
    memset(head, -1, sizeof(head));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if((i+j) % 2 == 0) {
                add(s, id[i][j], r[i][j]);
                for(int k=0;k<4;k++) {
                    int ti = i+to[k][0],
                        tj = j+to[k][1];
                    if(ti < 1 || ti > n || tj < 1 || tj > m)
                        continue;
                    add(id[i][j], id[ti][tj], 0x3f3f3f3f);
                }
            } else {
                add(id[i][j], t, r[i][j]);
            }
        }
    }
    ll sum = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++)
            sum += r[i][j];
    }
    cout << sum - dinic() << endl;
    return 0;
}