#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,f[maxn],ct[30];
string s;
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>s;
        for(int i=0;i<26;i++) ct[i]=0;
        long long ans=0;
        for(int i=n-1;i>=0;i--) {
            f[i]=n-i-ct[s[i]-'a'];
            ans+=f[i];
            ct[s[i]-'a']+=f[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}