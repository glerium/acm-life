#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
struct State {
    int x;
    ll dis;
    bool operator<(const State &rhs) const {
        return dis > rhs.dis;
    }
};
void solve() {
    int n,m,k,p; cin >> n >> m >> k >> p;
    ll mod = p;
    vector<vector<pair<int,ll>>> a(n+5);
    rep(i,1,m) {
        int x,y,z; cin >> x >> y >> z;
        a[x].push_back({y, z});
    }
    vector<ll> dis(n+5, inf);
    priority_queue<State> q;
    vector<bool> vis(n+5);
    q.push({1,0});
    dis[1] = 0;
    while(!q.empty()) {
        auto cur = q.top(); q.pop();
        auto [x, _] = cur;
        if(vis[x]) continue;
        vis[x] = true;
        for(auto [v, d] : a[x]) {
            if(dis[v] > dis[x] + d) {
                dis[v] = dis[x] + d;
                q.push({v, dis[v]});
            }
        }
    }
    auto f = Vec<ll>(n+5, k+5, 0);
    f[1][0] = 1 % mod;
    auto vis2 = Vec<bool>(n+5, k+5, false);
    auto inStack = Vec<bool>(n+5, k+5, false);
    bool ok = true;
    function<ll(int,int)> dfs = [&](int x, int k0) -> ll{
        if(inStack[x][k0]) {
            cout << -1 << endl;
            ok = false;
            return -1;
        }
        if(vis2[x][k0]) return f[x][k0];
        if(x == n && k0 == 0) f[x][k0] = (f[x][k0] + 1) % mod;
        inStack[x][k0] = true;
        for(auto [v, d] : a[x]) {
            int k1 = dis[x] + d + k0 - dis[v];
            if(k1 > k) continue;
            f[x][k0] += dfs(v, k1);
            f[x][k0] %= mod;
        }
        inStack[x][k0] = false;
        vis2[x][k0] = true;
        return f[x][k0];
    };
    ll ans = 0;
    rep(i,0,k) {
        rep(x,1,n) rep(y,0,k) inStack[x][y] = vis2[x][y] = false;
        ans = (ans + dfs(1, i)) % mod;
        if(!ok) return;
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