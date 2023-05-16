#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=998244353;
const int maxn=1e3+10;
const int maxm=maxn*maxn;
int n,m,k;
ll c[maxm];
ll qpow(ll a, ll b) {
    if(b==0) return 1;
    if(b&1) return qpow(a,b-1)*a%p;
    return qpow(a*a%p,b/2)%p;
}
void init() {
    c[k]=1;
    for(int i=k+1;i<=n*m;i++) {
        c[i]=(c[i-1]*i)%p;
        c[i]=(c[i]*qpow(i-k,p-2))%p;
    }
}
ll C(int x,int y) {
    if(x*y<k) return 0;
    return c[x*y];
}
int main() {
    cin>>n>>m>>k;
    init();
    ll ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {     // (i,j)
            ll u = C(i-1,m),
               d = C(n-i,m),
               l = C(n, j-1),
               r = C(n, m-j);
            ll ul = C(i-1,j-1),
               ur = C(i-1,m-j),
               dl = C(n-i,j-1),
               dr = C(n-i,m-j);
            ans += (C(n,m) - (u+d+l+r - ul-ur-dl-dr) + p) % p;
            ans %= p;
        }
    }
    ans = ans*qpow(C(n,m),p-2)%p;
    cout<<ans<<endl;
    return 0;
}