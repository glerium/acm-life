#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
ll jc[maxn], dp[maxn][30];
ll qpow(ll x, ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return x*qpow(x,y-1)%mod;
    return qpow(x*x%mod, y/2);
}
ll frac(ll x, ll y) {
    return x*qpow(y, mod-2)%mod;
}
ll C(int x, int y) {
    if(x < 0 || y < 0 || x < y) return 0;
    return frac(jc[x], jc[y] * jc[x-y] % mod);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    jc[0] = 1;
    for(int i=1;i<=2e5;i++)
        jc[i] = jc[i-1] * i % mod;
    int n,m; cin >> m >> n;
    for(int i=1;i<=m;i++) dp[i][0] = 1;
    for(int i=1;i<=m;i++) {
        for(int j=i+i;j<=m;j+=i) {
            for(int k=1;k<=25;k++) {
                dp[j][k] += dp[i][k-1];
                dp[j][k] %= mod;
            }
        }
    }
    ll all = C(m, n) * n % mod;
    ll sub = 0;
    for(int i=1;i<=m;i++) {
        for(int j=0;j<=25;j++) {
            sub += dp[i][j] * C(m/i-1, n-j-1) % mod;
            sub %= mod;
        }
    }
    cout << (all - sub + mod) % mod << endl;
    return 0;
}