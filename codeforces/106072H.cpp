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
ll qpow(ll x, ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y & 1) return x * qpow(x, y - 1) % mod;
    return qpow(x * x % mod, y / 2);
}
ll jc[3007];
void init() {
    jc[0] = 1;
    rep(i,1,3000) jc[i] = jc[i-1] * i % mod;
}
void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n+5);
    rep(i,1,n-1) {
        int x,y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    ll ans = 0;
    function<void(int,int,int)> dfs = [&](int x, int fa, int dep) -> void {
        // d! - 2(d-1)! + (d-2)!
        if(dep == 1) 0;
        else ans += ((jc[dep] - 2 * jc[dep - 1] + jc[dep - 2]) % mod + mod) % mod;
        ans %= mod;
        for(auto v : a[x]) {
            if(v == fa) continue;
            dfs(v, x, dep + 1);
        }
    };
    rep(i,1,n) {
        dfs(i, -1, 1);
    }
    cout << (ans * qpow(2, mod - 2) + 1) % mod << endl;
}
int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}