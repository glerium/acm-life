#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
constexpr int maxn = 1e6+10;
int n,m,q,head[maxn],ct,d[maxn],dis[maxn],from[maxn];
bitset<maxn> vis;
struct Edge {
    int to, nxt;
}a[maxn];
struct MFS {
    int fa[maxn];
    void init(int x) {
        for(int i=1;i<=x;i++)
            fa[i] = i;
    }
    int find(int x) {
        if(fa[x] == x)
            return x;
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        fa[x] = y;
    }
}mfs;
void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}
int dfs(int x, int fa, vector<int>& pt) {
    if(vis[x]) return 0;
    vis[x] = true;
    int ret = 0;
    ret = max(ret, dis[x]);
    pt.push_back(x);
    from[x] = fa;
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to == fa) continue;
        dis[a[i].to] = dis[x] + 1;
        ret = max(ret, dfs(a[i].to, x, pt));
    }
    return ret;
}
int find_d(int x) {
    vector<int> pt;
    dfs(x, -1, pt);
    int d1 = 0;
    for(auto i : pt) {
        if(dis[i] > dis[d1]) {
            d1 = i;
        }
    }
    for(auto i : pt) {
        from[i] = 0;
        vis[i] = false;
        dis[i] = 0;
    }
    pt.clear();
    int ret = 0;
    ret = dfs(d1, -1, pt);
    int d2 = 0;
    for(auto i : pt) {
        if(dis[i] > dis[d2]) {
            d2 = i;
        }
    }
    for(auto i : pt) {
        dis[i] = 0;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    mfs.init(n);
    for(int i=1;i<=m;i++) {
        int x, y; cin >> x >> y;
        mfs.merge(x, y);
        add(x, y);
        add(y, x);
    }
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            d[mfs.find(i)] = find_d(i);
        }
    }
    for(int i=1;i<=q;i++) {
        int op; cin >> op;
        if(op == 1) {
            int x; cin >> x;
            cout << d[mfs.find(x)] << endl;
        }else{
            int x, y; cin >> x >> y;
            int dx = d[mfs.find(x)], dy = d[mfs.find(y)];
            if(mfs.find(x) == mfs.find(y)) continue;
            int new_d = max({dx, dy, (dx+1)/2+(dy+1)/2+1});
            mfs.merge(x, y);
            d[mfs.find(x)] = new_d;
        }
    }
    return 0;
}
