#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void exgcd(ll a, ll b, ll &x, ll &y) {
    if(!b) {
        x = 1;
        y = 0;
    } else {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}
ll inv(ll a, ll m) {
    ll x, y;
    exgcd(a, m, x, y);
    return (x % m + m) % m;
}
ll mul(ll x, ll y, ll mod) {
    return (__int128)x * y % mod;
}
void solve() {
    int n; cin >> n;
    vector<ll> a(n+5), b(n+5);
    rep(i,1,n) cin >> a[i] >> b[i];
    ll N = 1;
    rep(i,1,n) N *= a[i];
    vector<ll> c(n+5);
    rep(i,1,n) {
        ll m = N / a[i];
        ll m_ = inv(m % a[i], a[i]);
        c[i] = m * m_ % N;
    }
    ll ans = 0;
    rep(i,1,n) {
        ans += mul(b[i], c[i], N);
        ans %= N;
    }
    if(ans == 0) ans += N;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}