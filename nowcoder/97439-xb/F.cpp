#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 5e5+10;
constexpr ll mod = 998244353;
struct Edge {
    int to, nxt;
} a[maxn << 1];
int ct, head[maxn], n, dep[maxn], dis[maxn], fa[maxn][25], sz[maxn], md[maxn];
void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}
void dfs(int x, int from) {
    fa[x][0] = from;
    dep[x] = dep[from] + 1;
    md[x] = 1;
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to == from)
            continue;
        sz[x]++;
        dfs(a[i].to, x);
        md[x] = max(md[x], 1 + md[a[i].to]);
    }
}
bool ok[maxn] = {};
void dfs2(int x) {
    ok[x] = false;
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to == fa[x][0])
            continue;
        dfs2(a[i].to);
    }
}
int getlca(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    for(int i=19;i>=0&&dep[x]!=dep[y];i--) {
        if(fa[x][i] && dep[fa[x][i]] >= dep[y]) {
            x = fa[x][i];
        }
    }
    if(x == y) return x;
    // dep[x] == dep[y]
    for(int i=19;i>=0;i--) {
        if(fa[x][i] && fa[y][i] && fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if(x == y) return x;
    return fa[x][0];
}
bool check(int d) {
    rep(i,1,n) ok[i] = dep[i] <= d;
    vector<int> vnok;
    rep(i,1,n) {
        if(!ok[i]) {
            vnok.push_back(i);
        }
    }
    if(vnok.empty()) {
        return true;
    }
    int lca = vnok[0];
    for(auto i : vnok)
        lca = getlca(lca, i);
    if(dep[lca] > d) {
        if(!fa[lca][0]) {
            return false;
        }
        ok[fa[lca][0]] = false;
        vnok.push_back(fa[lca][0]);
        lca = fa[lca][0];
    }
    // cout << d << endl;
    // for(auto i : vnok)
    //     cout << i << ' ';
    int len = 0;
    for(auto i : vnok) {
        len = max(len, dep[i] - dep[lca] + 1);
    }
    // cout << ":" << lca << ' ' << len << endl;
    // cout << ":" << len << endl;
    dfs2(lca);
    int tmp = lca;
    while(tmp) {
        ok[tmp] = false;
        tmp = fa[tmp][0];
    }
    for(int i=1;i<=n;i++) {
        if(!ok[i]) continue;
        if(dep[i] + len - 1 <= d && dep[lca] + md[i] - 1 <= d) {
            // cout << "ok at " << i << endl;
            return true;
        }
    }
    return false;
}
void solve() {
    cin >> n;
    rep(i,1,n-1) {
        int x, y; cin >> x >> y;
        add(x, y); add(y, x);
    }
    dfs(1, 0);
    rep(i,1,19) {
        rep(j,1,n) {
            fa[j][i] = fa[fa[j][i-1]][i-1];
        }
    }
    int mxdep = -1;
    rep(i,1,n)
        mxdep = max(mxdep, dep[i]);
    int l=1, r=mxdep, mid, ans;
    // for(int i=l;i<=r;i++)
    //     check(i);
    while(l <= r) {
        mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
