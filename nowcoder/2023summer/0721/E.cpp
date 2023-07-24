#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long t,n;
ll check(long long x) {
    if(ll(sqrtl(x))*ll(sqrtl(x))==x) return sqrtl(x);
    ll l = x*10, r=x*10+9;
    while(true) {
        long double lt = sqrtl(l), rt = sqrtl(r);
        // cout<<l<<' '<<r<<' '<<lt<<' '<<rt<<endl;
        if(lt>1e9) return -1;
        if(ceill(lt)<=floorl(rt)) return ceill(lt);
        l*=10;
        r=r*10+9;
    }
    return -1;
}
int main() {
    // cin>>t;
    ios::sync_with_stdio(false);
    t=1e5;
    n=0;
    while(t--) {
        n++;
        ll ans = check(n);
        if(ans>1e9) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}