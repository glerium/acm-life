#include <bits/stdc++.h>
using namespace std;
int t,n;
char s[10000];
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>s+1;
        char c=-1;
        string ans;
        for(int i=1;i<=n;i++) {
            char c=s[i];
            i++;
            while(s[i]!=c&&i<=n) i++;
            ans+=c;
        }
        cout<<ans<<endl;
    }
}