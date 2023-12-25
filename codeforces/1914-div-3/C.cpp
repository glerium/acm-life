#include <bits/stdc++.h>
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=1e3+10;
int t,n,k,a[maxn],b[maxn];
signed main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>k;
        rep(i,1,n) cin>>a[i];
        rep(i,1,n) cin>>b[i];
        long long ans=0,s=0;
        int mx=0;
        rep(i,1,min(n,k)) {
            s+=a[i];
            mx=max(mx,b[i]);
            ans=max(ans,s+(k-i)*1ll*mx);
        }
        cout<<ans<<endl;
    }
    return 0;
}