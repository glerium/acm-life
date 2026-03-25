#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
ll jc[maxn], njc[maxn];
ll qpow(ll x, ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return x * qpow(x, y - 1) % mod;
    return qpow(x * x % mod, y / 2);
}
ll frac(ll x, ll y) {
    return x * qpow(y, mod - 2) % mod;
}
void init() {
    jc[0] = 1;
    rep(i,1,1e5) jc[i] = jc[i-1] * i % mod;
    rep(i,0,1e5) njc[i] = frac(1, jc[i]);
}
ll C(ll x, ll y) {
    // x >= y
    return jc[x] * njc[y] % mod * njc[x - y] % mod;
}
void solve() {
    int n,k; cin >> n >> k;
    string s; cin >> s; s = ' ' + s;
    vector<int> vec = {0};
    rep(i,1,n) {
        if(s[i] == '1')
            vec.push_back(i);
    }
    vec.push_back(n+1);
    int m = vec.size() - 2;
    if(k > m) {
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    int lsl = -1, lsr = -1;
    for(int li=1,ri=k; li<=m&&ri<=m; li++,ri++) {
        int l = vec[li-1] + 1, r = vec[ri+1] - 1;
        int ct = r - l + 1;
        ans += C(ct, k);
        ans %= mod;
        if(lsl != -1) {
            ans -= C(lsr - l + 1, k - 1);
            ans = (ans % mod + mod) % mod;
        }
        lsl = l, lsr = r;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
