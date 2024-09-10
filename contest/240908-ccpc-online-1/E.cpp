#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
ll qpow(ll x, ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return x*qpow(x,y-1)%mod;
    return qpow(x*x%mod, y/2);
}
ll frac(ll x, ll y) {
    return x * qpow(y, mod-2) % mod;
}
ll mns(ll x, ll y) {
    return (x - y + mod) % mod;
}
int main() {
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    ll ans1 = 1;
    for(int i=1;i<=m;i++) {
        if(i >= 5) ans1 += n;
        else {
            ll tt = 1;
            for(int j=1;j<=i;j++)
                tt *= 26;
            ans1 += min(tt, n * 1ll);
        }
    }
    ans1 %= mod;
    ll ans = 1;
    for(int i=1;i<=m;i++) {
        ans += mns(1, qpow(mns(1, frac(1, qpow(26, i))), n)) * qpow(26, i) % mod;
        ans %= mod;
    }
    cout << ans1 << ' ' << ans << endl;
    return 0;
}