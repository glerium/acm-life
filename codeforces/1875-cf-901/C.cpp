#include <bits/stdc++.h>
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int _,n,m,mm,p;
int gcd(int x,int y) {
    return !y?x:gcd(y,x%y);
}
bool check() {
    int x=n,y=m;
    int t=gcd(n,m);
    x/=t,y/=t;
    p=gcd(n,m);
    for(int i=0;i<=40;i++) if(y==(1ll<<i)) {mm=i; return false;}
    return true;
}
signed main() {
    cin>>_;
    while(_--) {
        cin>>n>>m;
        n%=m;
        if(n==0) puts("0");
        else if(check()) puts("-1");
        else {
            int ans=m*__builtin_popcount(n/p)-n;
            // cout<<":"<<ans<<' '<<p<<endl;
            cout<<ans<<endl;
        }
    }
}