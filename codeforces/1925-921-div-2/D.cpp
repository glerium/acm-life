#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll mod=1e9+7;
constexpr int maxn=2e5+10;
int t,n,m,k;
ll fac[maxn],f[maxn];
ll qpow(ll x,ll y) {
    if(!x) return 0;
    if(!y) return 1;
    x%=mod, y%=mod;
    return y%2==0?qpow(x*x%mod,y/2):x*qpow(x,y-1)%mod;
}
ll frac(ll x,ll y) {
    return x*qpow(y,mod-2)%mod;
}
ll C(ll n,ll k) {
    if(n==k||k==0) return 1;
    if(k>n||k<0) return 0;
    return frac(fac[n],fac[k]*fac[n-k]%mod);
}
void init() {
    fac[0]=1;
    for(int i=1;i<=2e5+3;i++) fac[i]=fac[i-1]*i%mod;
}
int main() {
    ios::sync_with_stdio(false);
    init();
    cin>>t;
    while(t--) {
        cin>>n>>m>>k;
        for(int i=1;i<=m;i++) {
            int x,y;
            cin>>x>>y>>f[i];
        }
        if(n==2) {
            if(m==0) cout<<0<<endl;
            else cout<<(f[1]*k+k*(k-1)/2)%mod<<endl;
            continue;
        }
        ll d=1ll*n*(n-1)/2%mod;                   // d=C(n,2)
        ll ans=0;
        for(int i=1;i<=m;i++) ans+=f[i];
        ans=ans%mod*frac(k,d)%mod;
        for(int i=2;i<=k;i++) {
            ll nw=1ll*i*(i-1)/2%mod * C(k,i)%mod * qpow(frac(1,d),i)%mod * qpow(frac(d-1,d),k-i)%mod;
            ans=(ans+nw*m%mod)%mod;
        }
        cout<<ans<<endl;
    }
}