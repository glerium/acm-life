#include <bits/stdc++.h>
using namespace std;
int t,n;
string s;
int getsub(int start) {
    int ans=0;
    for(int i=start;i<start+5;i++) ans=ans*10+s[i]-'0';
    return ans;
}
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>s;
        string ans;
        for(int i=0;i<s.size();i+=5) {
            int now=getsub(i);
            string cur;
            for(int j=1;j<=3;j++) {
                cur+=now%26+'a';
                now/=26;
            }
            ans+=cur[2];
            ans+=cur[1];
            ans+=cur[0];
        }
        cout<<ans<<endl;
    }
    return 0;
}