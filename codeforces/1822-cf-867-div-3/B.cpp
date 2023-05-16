#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int t,n;
ll a[maxn];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        int ctpos=0, ctneg=0, ctzero=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>0) ctpos++;
            else if(a[i]<0) ctneg++;
            else ctzero++;
        }
        if(n==2) {
            cout<<a[1]*a[2]<<endl;
            continue;
        }
        ll ans=LLONG_MIN;
        if(ctpos>=2) {
            ll mx=-1, mx2=-1;
            for(int i=1;i<=n;i++) {
                if(a[i]>mx) {
                    mx2=mx;
                    mx=a[i];
                }else if(a[i]>mx2){
                    mx2=a[i];
                }
            }
            ans=max(ans,mx*mx2);
        }
        if(ctneg>=2) {
            ll mi=1, mi2=1;
            for(int i=1;i<=n;i++){
                if(a[i]<mi) {
                    mi2=mi;
                    mi=a[i];
                }else if(a[i]<mi2){
                    mi2=a[i];
                }
            }
            ans=max(ans,mi*mi2);
        }
        if(ctzero) ans=max(ans,0ll);
        if(ans<0) {
            ll ma=LLONG_MIN, mi=LLONG_MAX;
            for(int i=1;i<=n;i++) {
                if(a[i]<0 && a[i]>ma) ma=a[i];
                else if(a[i]>0 && a[i]<mi) mi=a[i];
            }
            ans=max(ans,mi*ma);
        }
        cout<<ans<<endl;
    }
    return 0;
}