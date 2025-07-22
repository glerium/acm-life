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
    if(y&1) return x * qpow(x, y - 1) % mod;
    return qpow(x * x % mod, y / 2);
}
ll frac(ll x, ll y) {
    return x * qpow(y, mod - 2) % mod;
}
struct Segment {
    int l,r;
    ll p, p1;
    bool operator<(const Segment& rhs) const {
        if(l != rhs.l) return l < rhs.l;
        else return r < rhs.r;
    }
};
void solve() {
    int n,m; cin >> n >> m;
    vector<Segment> a(n+5);
    rep(i,1,n) {
        cin >> a[i].l >> a[i].r;
        ll x, y; cin >> x >> y;
        a[i].p = frac(x, y);
        a[i].p1 = frac(a[i].p, (1 - a[i].p + mod) % mod);
    }
    sort(a.begin() + 1, a.begin() + 1 + n);
    vector<ll> f(n+5), g(m+5);
    g[0] = 1;
    rep(i,1,n) {
        f[i] = a[i].p1 * g[a[i].l - 1] % mod;
        g[a[i].r] += f[i];
        g[a[i].r] %= mod;
    }
    ll ans = g[m];
    rep(i,1,n) ans = ans * (1 - a[i].p + mod) % mod;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}