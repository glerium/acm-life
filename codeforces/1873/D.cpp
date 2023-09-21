#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int t,n,k;
string s;
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k>>s;
        int ans=0,st=0;
        bool in=false;
        rep(i,0,n-1) {
            if(i-st+1>k) {
                in=false;
            }
            if(!in) {
                if(s[i]=='W') continue;
                else st=i, in=true, ans++;
            }else{
                if(i-st+1>k) {
                    in=false;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}