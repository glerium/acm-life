#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 2e3+10;
int n,m,head[maxn],ct,cur[maxn],level[maxn];
struct Edge {
    int to, nxt;
    ll cap;
}a[maxn<<1];
void add(int x, int y, ll w) {
    a[ct] = {y, head[x], w};
    head[x] = ct++;
    a[ct] = {x, head[y], 0};
    head[y] = ct++;
}
bool dinic_bfs() {
    memset(level, 0, sizeof(level));
    level[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int i=head[now];~i;i=a[i].nxt) {
            if(level[a[i].to]) continue;
            if(!a[i].cap) continue;
            level[a[i].to] = level[now] + 1;
            q.push(a[i].to);
            if(a[i].to == n) return true;
        }
    }
    return false;
}
ll dinic_dfs(int x, ll lim) {
    if(x == n) return lim;
    ll ret = 0;
    for(int &i=cur[x];~i;i=a[i].nxt) {
        int v = a[i].to;
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
        ll now = dinic_dfs(1, 0x3f3f3f3f3f3f3f3f);
        ans += now;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    for(int i=1;i<=m;i++) {
        int x,y; ll w;
        cin >> x >> y >> w;
        add(x,y,w*2000+1);
    }
    ll ans = dinic();
    cout << ans / 2000 << ' ' << ans % 2000 << endl;
    return 0;
}