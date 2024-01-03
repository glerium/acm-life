#include <bits/stdc++.h>
using namespace std;
int t,n;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        long long s=0;
        for(int i=1;i<=n;i++) {
            int tt; cin>>tt;
            s+=tt;
        }
        if(round(sqrt(s))*round(sqrt(s))==s) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}