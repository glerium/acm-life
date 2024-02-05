#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=1e5+10;
constexpr ll mod=1e9+7;
int n,m;
ll fac[maxn];
ll qpow(ll x,ll y) {
//     cout<<x<<' '<<y<<endl;
    if(!x) return 0;
    if(!y) return 1;
    return y%2==0?qpow(x*x%mod,y/2):x*qpow(x,y-1)%mod;
}
ll frac(ll x,ll y){
//     cout<<x<<' '<<y<<endl;
    return x*qpow(y%mod,mod-2)%mod;
}
ll minus_1(ll n) {
    return (n&1)?-1:1;
}
ll S(ll n,ll m) {
    ll ans=0;
    for(int i=0;i<=m;i++) {
//         cout<<i<<endl;
        ans=(ans+frac(qpow(i,n),fac[i]*fac[m-i])*minus_1(m-i)+mod)%mod;
//         cout<<qpow(i,n)<<' '<<fac[i]*fac[m-i]<<' '<<minus_1(m-i)<<endl;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    fac[0]=1;
    rep(i,1,1e5) fac[i]=fac[i-1]*i%mod;
    cin>>n>>m;
    if(n<m) cout<<0<<endl;
    else cout<<S(n,m)<<endl;
    return 0;
}