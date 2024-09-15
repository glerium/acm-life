#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
constexpr int maxn = 503;
ll jc[maxn];
ll qpow(ll x,ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return x*qpow(x,y-1)%mod;
    return qpow(x*x%mod, y/2);
}
ll frac(ll x, ll y) {
    return x * qpow(y, mod - 2) % mod;
}
ll A(ll n, ll m) {
    return frac(jc[n], jc[m]);
}
ll C(ll n, ll m) {
    return frac(A(n, m), jc[n-m]);
}
int main() {
    jc[0] = 1;
    for(int i=1;i<=500;i++)
        jc[i] = jc[i-1] * i % mod;
    

    int n,m; cin>>n>>m;
    int a[n+5], b[m+5];
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) cin >> b[i];
    int p[n+5]={}, g[n+5]={};
    rep(i,1,n) p[b[i]]++;
    rep(i,1,m) g[a[i]]++;
    ll f[maxn][maxn] = {};
    f[0][0] = 1;
    ll ans = 0;
    for(int d=1;d<=500;d++) {
        if(a[1]-d <= 0)
            continue;
        for(int i=1;i<=500;i++) {
            if(!p[i] && !g[i]) {
                memcpy(f[i], f[i-1], sizeof(f[i]));
            }else if(!p[i] && g[i]) {
                for(int j=g[i];j<=500;j++) {
                    f[i][j] = f[i-1][j-g[i]];
                }
            }else if(p[i] && !g[i]) {
                for(int j=0;j<=500;j++) {
                    for(int k=0;k<=p[i]&&j+k<=500;k++) {
                        f[i][j] += f[i-1][j+k] * C(k, p[i]) % mod * A(j+k, k) % mod;
                        f[i][j] %= mod;
                    }
                }
            }else{
                for(int j=0;j<=500;j++) {
                    for(int k=0;k<=p[i];k++) {
                        if(j+k-g[i]<0 || j+k-g[i]>500)
                            continue;
                        f[i][j] += f[i-1][j+k-g[i]] * C(k, p[i]) % mod * A(j+k-p[i], k) % mod;
                        f[i][j] %= mod;
                    }
                }
            }
        }
        for(int i=0;i<=500;i++) {
            ans += f[500][i] * d % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
}