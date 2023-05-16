#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int t,n,a[maxn];
int ct[maxn];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        int mx=0;
        for(int i=1;i<=n;i++) cin>>a[i], mx=max(mx,a[i]);
        for(int i=1;i<=n;i++) ct[a[i]]++;
        long long ans=0;
        // for(int i=1;i<=mx;i++) if(ct[i]>=3) ans+=1ll*ct[i]*(ct[i]-1)*(ct[i]-2);
        for(int i=1;i<=n;i++) {
            ans += 1ll*(ct[a[i]]-1)*(ct[a[i]]-2);
            for(int j=2;a[i]*j*j<=mx;j++) {
                ans += 1ll*ct[a[i]*j]*ct[a[i]*j*j];
            }
        }
        // for(int i=2;i*i<=mx;i++) {
        //     for(int j=1;j*i*i<=mx;j++) {
        //         ans += 1ll*ct[j]*ct[j*i]*ct[j*i*i];
        //     }
        // }
        for(int i=1;i<=n;i++) ct[a[i]]--;
        cout<<ans<<endl;
    }
    return 0;
}