#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=1e5+10;
int t,n,k,d,a[maxn],v[maxn];
int count() {
    int ct=0;
    for(int i=1;i<=n;i++) ct+=a[i]==i;
    return ct;
}
bool check() {
    for(int i=1;i<=n;i++) if(a[i]) return false;
    return true;
}
signed main() {
    cin>>t;
    while(t--) {
        cin>>n>>k>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=k;i++) cin>>v[i];
        int ans=count()+(d-1)/2;
        if(check()) ans=max(ans, d/2);
        for(int i=1;i<=min(2*n,d-1);i++) {
            int mxi=v[i%k?i%k:k];
            for(int j=1;j<=mxi;j++)
                a[j]++;
            ans=max(ans,count()+(d-i-1)/2);
        }
        cout<<ans<<endl;
    }
    return 0;
}