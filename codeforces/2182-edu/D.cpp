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
ll jc[60];
ll qpow(ll x, ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return qpow(x, y - 1) * x % mod;
    return qpow(x * x % mod, y / 2);
}
ll frac(ll x, ll y) {
    return x * qpow(y, mod - 2) % mod;
}
ll C(ll x, ll y) {
    if(x < y) return 0;
    return frac(jc[x], jc[y] * jc[x - y] % mod);
}
void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    rep(i,0,n) cin >> a[i];
    int mx = *max_element(a.begin() + 1, a.begin() + 1 + n);
    int turns = mx - 1;
    int delta = 0;
    rep(i,1,n) {
        delta += max(0, turns - a[i]);
    }
    if(delta > a[0]) {
        cout << 0 << endl;
        return;
    }
    int k = a[0] - delta;
    int m = 0;
    rep(i,1,n) {
        if(a[i] == mx)
            m ++;
    }
    // cout << m << ' ' << k << endl;
    swap(m, k);
    if(m + k >= n) {
        cout << jc[n] << endl;
    } else {
        cout << C(m+k, k) * jc[k] % mod * jc[n - k] % mod << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    jc[0] = 1;
    rep(i,1,50)
        jc[i] = jc[i-1] * i % mod;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}