#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(long long i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e6+10;
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
    if(!y) return 1;
    if(y&1) return qpow(x, y - 1) * x % mod;
    return qpow(x * x % mod, y >> 1) % mod;
}
ll div(ll y) {
    return qpow(y, mod - 2);
}
ll frac(ll x, ll y) {
    return x * div(y) % mod;
}
ll jc[maxn];
ll C(ll x, ll y) {
    return frac(jc[x], jc[y] * jc[x - y] % mod);
}
void solve() {
    ll n,m,k; cin >> n >> m >> k;
    ll ans = 0;
    rep(i,1,k) {
        ll x = C(k, i) * i % mod * qpow(i - 1, n - 1) % mod;
        int sgn = (k - i) % 2 == 0 ? 1 : -1;
        ans = ((ans + x * sgn) % mod + mod) % mod;
    }

    rep(i,m-k+1,m) ans = ans * i % mod;
    rep(i,1,k) ans = ans * div(i) % mod;
    
    cout << ans << endl;
}
int main() {
    jc[0] = 1;
    rep(i,1,1e6) jc[i] = jc[i - 1] * i % mod;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}