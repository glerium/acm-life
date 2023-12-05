#include <bits/stdc++.h>
using namespace std;
int t,n,ct[26];
string s;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>s;
        for(int i=0;i<26;i++) ct[i]=0;
        for(auto i:s) ct[i-'a']++;
        int mx=*max_element(ct, ct+26);
        int ans;
        if(n&1) ans=max(1,max(0,mx-(n-mx)));
        else ans=max(0, mx-(n-mx));
        cout<<ans<<endl;
    }
    return 0;
}