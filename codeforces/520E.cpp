#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
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
ll jc[maxn], ten[maxn], pt[maxn], pts[maxn];
ll qpow(ll x, ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return x * qpow(x, y - 1) % mod;
    return qpow(x * x % mod, y >> 1);
}
ll frac(ll x, ll y) {
    return x * qpow(y, mod - 2) % mod;
}
ll C(ll x, ll y) {
    if(x < 0 || y < 0) return 0;
    if(x < y) return 0;
    return frac(jc[x], jc[y] * jc[x - y] % mod);
}
void solve() {
    int n,m; cin >> n >> m;
    string s; cin >> s; s = ' ' + s;
    vector<int> a(n+5);
    rep(i,1,n) a[i] = s[i] - '0';
    if(m == 0) {
        ll ans = 0;
        rep(i,1,n) ans = (ans * 10 + a[i]) % mod;
        cout << ans << endl;
        return;
    }
    rep(k,0,n) pt[k] = C(n - k - 2, m - 1) * ten[k] % mod;
    pts[0] = pt[0];
    rep(i,1,n) pts[i] = (pts[i-1] + pt[i]) % mod;

    ll ans = 0;
    rep(i,1,n) {
        ans = (ans + a[i] * pts[n - i - 1] % mod) % mod;
        // rep(k,0,n-i-1) {
        //     ans += a[i] * C(n - k - 2, m - 1) * ten[k];
        // }
        ans = (ans + a[i] * ten[n-i] % mod * C(i-1, m) % mod) % mod;
    }
    cout << ans << endl;
}
void init() {
    jc[0] = 1;
    rep(i,1,1e5) jc[i] = jc[i-1] * i % mod;
    ten[0] = 1;
    rep(i,1,1e5) ten[i] = ten[i-1] * 10 % mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t = 1;
    while(t--) solve();
    return 0;
}