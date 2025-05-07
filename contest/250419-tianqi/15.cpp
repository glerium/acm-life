#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    }else{
        return vector(n, Vec<T>(args...));
    }
}
constexpr ll mod = 998244353;
ll qpow(ll x, ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return x * qpow(x, y-1) % mod;
    return qpow(x*x%mod, y/2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> g(n+5);
    rep(i,2,n) {
        int x; cin >> x;
        g[x].push_back(i);
    }
    vector<int> c(n+5);
    rep(i,1,n) cin >> c[i];
    set<ll> st;
    vector<int> now;
    vector<bool> vis(n+5);
    ll ans = 0;
    function<vector<int>(int)> poll = [&](int x) -> vector<int> {
        vector<int> vec;
        if(!vis[x]) {
            vis[x] = true;
            vec.push_back(x);
        }
        for(auto v : g[x]) {
            if(vis[v]) continue;
            vis[v] = true;
            vec.push_back(v);
            auto tmp = poll(v);
            for(auto i : tmp)
                vec.push_back(i);
        }
        return vec;
    };
    function<void(int,ll)> dfs = [&](int x, ll money) -> void {
        bool ok = false;
        rep(i,1,n) {
            if(!vis[i])
                ok = true;
        }
        if(!ok) {
            ll tmp = 0;
            for(auto i : now) {
                tmp = (tmp * 233 + i) % mod;
            }
            if(!st.count(tmp)) {
                ans += money;
                ans %= mod;
                st.insert(tmp);
            }
            return;
        }
        for(int i=1;i<=n;i++) {
            if(!vis[i]) {
                auto vec = poll(i);
                ll n_money = qpow(c[x], vec.size());
                dfs(x+1, n_money);
                for(auto j : vec) {
                    vis[j] = false;
                }
            }
        }
    };
    dfs(1, 1);
    cout << ans << endl;
}