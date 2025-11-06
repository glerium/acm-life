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
auto f = Vec<ll>(12, 70, 1026, -1);
ll query(ll x, int b) {
    vector<int> a(1);
    while(x) {
        a.push_back(x % b);
        x /= b;
    }
    int n = a.size() - 1;
    
    auto dfs = [&](auto &&dfs, int pos, int state, bool top, bool first) -> ll {
        if(pos == 0) return state == 0;
        if(!top && !first && f[b][pos][state] != -1) return f[b][pos][state];
        int lim = top ? a[pos] : b - 1;
        ll ans = 0;
        rep(i,0,lim) {
            bool ntop = top && i == a[pos];
            if(first) {
                if(i == 0) ans += dfs(dfs, pos - 1, state, ntop, first);
                else ans += dfs(dfs, pos - 1, state ^ (1 << i), ntop, false);
            } else {
                ans += dfs(dfs, pos - 1, state ^ (1 << i), ntop, first);
            }
        }
        if(!top && !first) f[b][pos][state] = ans;
        return ans;
    };
    return dfs(dfs, n, 0, true, true);
}
void solve() {
    ll b,l,r;
    cin >> b >> l >> r;
    // cerr << query(r, b) << ' ' << query(l - 1, b) << endl;
    cout << query(r, b) - query(l - 1, b) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}