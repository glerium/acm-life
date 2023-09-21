#include <bits/stdc++.h>
using namespace std;
int t,n,a[20];
int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int mi=100,mii;
        for(int i=1;i<=n;i++) {
            if(mi>a[i]) {
                mi=a[i];
                mii=i;
            }
        }
        a[mii]++;
        int ans=1;
        for(int i=1;i<=n;i++) ans*=a[i];
        cout<<ans<<endl;
    }
    return 0;
}