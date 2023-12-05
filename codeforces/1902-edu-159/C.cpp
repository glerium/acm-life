#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=2e5+10;
int t,n;
ll a[maxn];
int gcd(int x,int y) {
    return !y?x:gcd(y,x%y);
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        if(n==1) {
            cout<<1<<endl;
            continue;
        }
        sort(a+1,a+1+n);
        for(int i=n;i>=1;i--) a[i]-=a[1];
        ll kk=a[1];
        rep(i,1,n) kk=gcd(kk,a[i]);
        rep(i,1,n) a[i]/=kk;
        ll ins=0;
        for(int i=n;i>1;i--) {
            if(a[i]!=a[i-1]+1) {
                ins=a[i]-1;
                break;
            }
        }
        if(ins==0) ins=a[1]-1;
        ll ans=0;
        rep(i,1,n) ans+=a[n]-a[i];
        ans+=a[n]-ins;
        cout<<ans<<endl;
    }
    return 0;
}