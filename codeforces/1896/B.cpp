#include <bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>s;
        int ans=n;
        bool check=false;
        for(int i=0;i<n;i++) {
            if(s[i]=='A') break;
            ans--;
        }
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='B') break;
            ans--;
        }
        ans--;
        cout<<max(0,ans)<<endl;
    }
    return 0;
}