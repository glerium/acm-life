#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
int head[maxn], ct;
struct Edge {
    int to, nxt;
} g[maxn << 1];
void add(int x, int y) {
    g[++ct] = {y, head[x]};
    head[x] = ct;
}
void solve() {
    ct = 0;
    memset(head, 0, sizeof(head));
    int n; cin >> n;
    int a[n+5]; rep(i,1,n) cin >> a[i];
    int t[n+5]; rep(i,1,n) cin >> t[i];
    for(int i=1;i<=n-1;i++) {
        int x, y; cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    bool vis[n+5] = {};
    ll f[n+5] = {};
    ll s[n+5] = {};
    f[0] = a[1];
    function<ll(int,int)> dfs = [&](int x, int fa) -> ll {
        if(vis[x]) return f[x];
        vis[x] = true;
        for(int i=head[x];i;i=g[i].nxt) {
            if(g[i].to == fa) continue;
            s[x] += dfs(g[i].to, x);
        }
        for(int i=head[x];i;i=g[i].nxt) {
            if(g[i].to == fa) continue;
            f[x] = max(f[x], a[g[i].to] + s[x]);
        }

        ll mx=0, mx2=0, mxi=-1, mxi2=-1;
        for(int i=head[x];i;i=g[i].nxt) {
            if(g[i].to == fa) continue;
            ll tmp = - f[g[i].to] + a[g[i].to] + s[g[i].to];
            if(tmp >= mx) {
                mx2 = mx;
                mxi2 = mxi;
                mx = tmp;
                mxi = g[i].to;
            } else if(tmp > mx2) {
                mx2 = tmp;
                mxi2 = g[i].to;
            }
        }
        for(int i=head[x];i;i=g[i].nxt) {
            if(g[i].to == fa) continue;
            if(t[g[i].to] != 3) continue;
            if(g[i].to != mxi) {
                f[x] = max(f[x], s[x] + mx + a[g[i].to]);
            } else if(mxi2 != -1) {
                f[x] = max(f[x], s[x] + mx2 + a[g[i].to]);
            }
        }
        return f[x];
    };
    dfs(1, 0);
    ll out = 0;
    for(int i=1;i<=n;i++)
        out = max(out, f[i]);
    cout << out + a[1] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
