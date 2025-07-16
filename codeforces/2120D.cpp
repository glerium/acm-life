#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(ll i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 1e9+7;
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
    return qpow(x * x % mod, y >> 1) % mod;
}
ll frac(ll x, ll y) {
    return x * qpow(y, mod - 2) % mod;
}
ll C(ll n, ll m) {
    // n, ..., n - m + 1
    // m, ..., 1
    ll ans = 1;
    for(ll i = n - m + 1; i <= n; i++) {
        if(i <= 0) return 0;
        ans = ans * i % mod;
    }
    rep(i,1,m) ans = ans * frac(1, i) % mod;
    return ans;
}
void solve() {
    ll a,b,k; cin >> a >> b >> k;
    ll n = k * (a - 1) % mod + 1;
    // cout << n << ' ' << a << ' ' << C(n, a) << ' ' << b - 1 << ' ' << 1 << endl;
    ll m = (k * C(n, a) % mod * (b - 1) % mod + 1) % mod;
    cout << n << ' ' << m << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}