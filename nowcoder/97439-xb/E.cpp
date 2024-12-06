#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e6+10;
constexpr ll mod = 998244353;
struct Edge {
    int to, nxt; 
} a[maxn << 1];
int ct, head[maxn], n, dep[maxn], dis[maxn], fa[maxn];
bool onroad[maxn], vis[maxn];
void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}
void dfs(int x, int from) {
    fa[x] = from;
    dep[x] = dep[from] + 1;
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to == from)
            continue;
        dfs(a[i].to, x);
    }
}
void dfs2(int x, int from) {
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to == from || vis[a[i].to] || onroad[a[i].to])
            continue;
        dis[a[i].to] = dis[x] + 1;
        vis[a[i].to] = true;
        dfs2(a[i].to, x);
    }
}
void solve() {
    cin >> n;
    rep(i,1,n-1) {
        int x, y; cin >> x >> y;
        add(x, y); add(y, x);
    }
    dfs(1, 0);
    int mx = -1, mxi;
    rep(i,1,n) {
        if(dep[i] > mx) {
            mx = dep[i];
            mxi = i;
        }
    }
    while(mxi) {
        onroad[mxi] = true;
        mxi = fa[mxi];
    }
    rep(i,1,n) {
        if(!onroad[i])
            continue;
        vis[i] = true;
        dfs2(i, 0);
    }
    int ans = mx;
    rep(i,1,n) {
        // cout << dis[i] << endl;
        ans = max(ans, mx - 1 + dis[i]);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
