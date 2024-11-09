#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn = 2e5+10;
int n, head[maxn], ct, dis[maxn], fa[maxn], disa[maxn], disb[maxn];
bitset<maxn> vis;
struct Edge {
    int to, nxt, len;
}a[maxn << 1];
void add(int x, int y, int z) {
    a[++ct] = {y, head[x], z};
    head[x] = ct;
}
void dfs(int x, int from, int dis[]) {
    fa[x] = from;
    for(int i=head[x];i;i=a[i].nxt) {
        if(vis[a[i].to])
            continue;
        if(a[i].to == from)
            continue;
        vis[a[i].to] = true;
        dis[a[i].to] = dis[x] + a[i].len;
        dfs(a[i].to, x, dis);
    }
}
int solve() {
    vis.reset();
    dfs(1, -1, dis);

    int d1 = 1;
    for(int i=1;i<=n;i++) {
        if(dis[i] > dis[d1]) {
            d1 = i;
        }
    }

    memset(dis, 0, sizeof(dis));
    vis.reset();
    dfs(d1, -1, dis);

    int d2 = d1;
    for(int i=1;i<=n;i++) {
        if(dis[i] > dis[d2]) {
            d2 = i;
        }
    }

    int d = 0;
    for(int i=1;i<=n;i++)
        d = max(d, dis[i]);

    vis.reset();
    dfs(d1, -1, disa);
    vis.reset();
    dfs(d2, -1, disb);

    int ret = 0;
    for(int i=1;i<=n;i++) {
        ret = max(ret, d + min(disa[i], disb[i]));
    }
    return ret;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m; 
    cin >> n >> m;
    for(int i=1;i<=m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    cout << solve() << endl; 
    return 0;
}
