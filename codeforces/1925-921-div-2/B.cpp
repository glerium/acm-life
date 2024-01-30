#include <bits/stdc++.h>
using namespace std;
int t,x,n;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>x>>n;
        int ans=0;
        for(int i=1;i*i<=x;i++) {
            if(x%i==0) {
                if(x/i>=n) ans=max(ans,i);
                if(i>=n) ans=max(ans,x/i);
            }
        }
        cout<<ans<<endl;
    }
}