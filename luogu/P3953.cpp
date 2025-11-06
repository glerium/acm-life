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
    vector<vector<pair<int,ll>>> a(n+5), b(n+5);
    rep(i,1,m) {
        int x,y,z; cin >> x >> y >> z;
        a[x].push_back({y, z});
        b[y].push_back({x, z});
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

    auto f = Vec<ll>(n+5, k+5, -1);
    auto instk = Vec<bool>(n+5, k+5, false);
    bool ok = true;
    function<ll(int,int)> dfs = [&](int v, int k1) -> ll{
        if(instk[v][k1]) {
            ok = false;
            cout << -1 << endl;
            return -1;
        }
        if(f[v][k1] != -1) return f[v][k1];
        instk[v][k1] = true;
        f[v][k1] = 0;
        for(auto [x, d] : b[v]) {
            int k0 = dis[v] + k1 - d - dis[x];
            if(k0 > k || k0 < 0) continue;
            f[v][k1] += dfs(x, k0);
            f[v][k1] %= mod;
            if(!ok) return -1;
        }
        if(v == 1 && k1 == 0) {
            f[v][k1] = (f[v][k1] + 1) % mod;
        }
        instk[v][k1] = false;
        return f[v][k1];
    };
    ll ans = 0;
    rep(i,0,k) {
        ans = (ans + dfs(n, i)) % mod;
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
