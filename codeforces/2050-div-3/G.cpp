#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
int head[maxn], ct, sz[maxn], f[maxn], g[maxn];
struct Edge {
    int to, nxt;
}a[maxn << 1];
void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}
void solve() {
    int n; cin >> n;
    ct = 0;
    memset(head, 0, sizeof(head[0]) * (n+5));
    memset(sz, 0, sizeof(sz[0]) * (n+5));
    memset(f, 0, sizeof(sz[0]) * (n+5));
    memset(g, 0, sizeof(sz[0]) * (n+5));
    for(int i=1;i<=n-1;i++) {
        int x, y; cin >> x >> y;
        add(x, y); add(y, x);
    }
    function<void(int,int)> dfs = [&](int x, int fa) -> void {
        sz[x] = 0;
        int mx=-1, mx2=-1;
        for(int i=head[x];i;i=a[i].nxt) {
            if(a[i].to == fa) continue;
            sz[x]++;
            dfs(a[i].to, x);
            int ret = g[a[i].to];
            if(ret > mx) {
                mx2 = mx;
                mx = ret;
            }else if(ret > mx2){
                mx2 = ret;
            }
        }
        g[x] = max({sz[x], sz[x] + mx - 1});
        f[x] = max({sz[x], sz[x] + mx - 1, sz[x] + mx + mx2 - 2});
    };
    dfs(1, -1);
    int ans = 0;
    rep(i,1,n) {
        ans = max(ans, f[i] + (i != 1));
        // cout << f[i] << ';' << endl;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
