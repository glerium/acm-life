#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,ans=1000000;
    cin>>n;
    while(n--) {
        int t;cin>>t;
        ans=min(ans,int(abs(t)));
    }
    cout<<ans<<endl;
    return 0;
}