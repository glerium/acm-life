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
struct BIT {
    vector<int> f;
    int n;
    void init(int x) {
        f.resize(x + 5);
        this->n = x;
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int v) {
        while(x <= n) {
            f[x] += v;
            x += lowbit(x);
        }
    }
    int query(int x) {
        int ans = 0;
        while(x) {
            ans += f[x];
            x -= lowbit(x);
        }
        return ans;
    }
} bit;
void solve() {
    int n; cin >> n;
    bit.init(n);
    vector<int> p(n+5);
    rep(i,1,n) cin >> p[i];
    map<int,int> mp;
    {
        auto a = p;
        sort(a.begin() + 1, a.begin() + 1 + n);
        int ct = 0;
        rep(i,1,n) {
            if(a[i] != a[i-1]) {
                mp[a[i]] = ++ct;
            }
        }
        rep(i,1,n) p[i] = mp[p[i]];
    }
    vector<vector<int>> g(n+5);
    rep(v,2,n) {
        int u; cin >> u;
        g[u].push_back(v);
    }
    vector<int> ans(n+5);
    auto dfs = [&](auto&& dfs, int u) -> void {
        ans[u] -= bit.query(n) - bit.query(p[u]);
        bit.add(p[u], 1);
        for(auto v : g[u]) {
            dfs(dfs, v);
        }
        ans[u] += bit.query(n) - bit.query(p[u]);
    };
    dfs(dfs, 1);
    rep(i,1,n) cout << ans[i] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}