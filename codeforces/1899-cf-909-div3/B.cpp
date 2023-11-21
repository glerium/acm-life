#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=1e6+10;
int t,n;
ll a[maxn],s[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        s[0]=0;
        rep(i,1,n) cin>>a[i], s[i]=s[i-1]+a[i];
        ll ans=-1;
        rep(i,1,n) {
            ll mx=-1,mi=1e18;
            if(n%i!=0) continue;
            for(int l=1,r=i;r<=n;l+=i,r+=i) {
                ll cur=s[r]-s[l-1];
                mx=max(mx,cur);
                mi=min(mi,cur);
            }
            ans=max(mx-mi,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}