#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,d,t[105];
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>t[i];
    int ans=-1;
    for(int i=2;i<=n;i++) {
        if(t[i]-t[i-1]<=d) {
            ans=t[i];
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}