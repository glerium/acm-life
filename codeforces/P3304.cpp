#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn = 2e5+10;
int n,head[maxn],ct,dis[maxn],fa[maxn];
bitset<maxn> vis;
vector<int> vec;
set<pair<int,int>> cp;
struct Edge {
    int to, nxt, len;
}a[maxn << 1];
void add(int x, int y, int z) {
    a[++ct] = {y, head[x], z};
    head[x] = ct;
}
void dfs(int x, int from, vector<int> &vec) {
    fa[x] = from;
    vec.push_back(x);
    for(int i=head[x];i;i=a[i].nxt) {
        if(vis[a[i].to])
            continue;
        if(a[i].to == from)
            continue;
        vis[a[i].to] = true;
        dis[a[i].to] = dis[x] + a[i].len;
        dfs(a[i].to, x, vec);
    }
}
int getd() {
    vis.reset();
    vec.clear();
    cp.clear();
    dfs(1, -1, vec);
    int d1 = 1;
    for(int i=1;i<=n;i++) {
        if(dis[i] > dis[d1]) {
            d1 = i;
        }
    }
    for(auto i : vec) {
        vis[i] = false;
        dis[i] = 0;
    }
    vec.clear();
    dfs(d1, -1, vec);
    int d2 = d1;
    for(int i=1;i<=n;i++) {
        if(dis[i] > dis[d2]) {
            d2 = i;
        }
    }
    int ret = 0;
    for(int i=1;i<=n;i++)
        ret = max(ret, dis[i]);
    for(int i=d2; fa[i]!=-1; i=fa[i]) {
        cp.insert({i, fa[i]});
        cp.insert({fa[i], i});
    }
    for(auto i : vec) {
        dis[i] = 0;
    }
    return ret;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1, x, y, z; i <= n-1;i++) {
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    int ans1 = getd();
    for(int i=1;i<=n;i++) {
        for(int j=head[i];j;j=a[j].nxt) {
            int x = i, y = a[j].to;
            if(cp.count({x, y})) {
                a[j].len--;
            }
        }
    }
    int ans2 = getd();
    cout << ans1 << endl << ans1 - ans2 << endl;
    return 0;
}
