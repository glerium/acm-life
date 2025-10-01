#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void solve() {
    int n,m; cin >> n >> m;
    vector<vector<pair<int,int>>> g(n+5);
    rep(i,1,m) {
        int u,v,w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<bool> vis(n+5);
    auto dfs = [&](auto &&dfs, int u, int diff) {
        if(vis[u]) return;
        vis[u] = true;
        for(auto [v, w] : g[u]) {
            if(!(w & (1 << diff))) {
                dfs(dfs, v, diff);
            }
        }
    };
    int ans = 0;
    rep(d,0,30) {
        rep(i,1,n) vis[i] = false;
        dfs(dfs, 1, d);
        if(!vis[n]) ans |= 1 << d;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}