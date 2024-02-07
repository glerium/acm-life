#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll a[1007];
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    bool allneg=true;
    for(int i=1;i<=n;i++) allneg&=a[i]==0;
    if(allneg) {
        ll ans=-1e10;
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
        cout<<ans<<endl;
        return 0;
    }
    if(k==0) {
        ll ans=0,ima=0;
        for(int i=1;i<=n;i++) {
            ima=max(ima+a[i],0ll);
            ans=max(ans,ima);
        }
        cout<<ans<<endl;
    }else{
        ll ans=0;
        for(int i=1;i<n;i++) {
            swap(a[i],a[i+1]);
            ll ima=0;
            for(int j=1;j<=n;j++) {
                ima=max(ima+a[j],0ll);
                ans=max(ans,ima);
            }
            swap(a[i],a[i+1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}