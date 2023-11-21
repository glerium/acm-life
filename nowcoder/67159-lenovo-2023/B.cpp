#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll p=1e9+7;
ll n,x,y,z;
ll qpow(ll x,ll y) {
    if(!y) return 1;
    if(y&1) return x*qpow(x,y-1)%p;
    return qpow(x*x%p,y/2);
}
ll calc(ll n,ll x) {
    ll ret=1;
    for(ll i=n;i>=n-x+1;i--) ret=ret*i%p;
    for(ll i=1;i<=x;i++) ret=ret*qpow(i,p-2)%p;
    return ret;
}
int main() {
    cin>>n>>x>>y>>z;
    ll ans=(qpow(2,n)+p-1)%p;
    ans=(ans+p-calc(n,x))%p;
    ans=(ans+p-calc(n,y))%p;
    ans=(ans+p-calc(n,z))%p;
    cout<<ans<<endl;
    return 0;
}