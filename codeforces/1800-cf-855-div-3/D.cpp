#include <bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>s;
        int ans=n-1;
        for(int i=0;i+2<n;i++) {
            if(s[i]==s[i+2]) ans--;
        }
        cout<<ans<<endl;
    }
    return 0;
}