#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
int t;
string s,ss;
int main() {
    cin>>t;
    while(t--) {
        cin>>s;
        int n=s.size(),ans=0;
        bool same=true,found=false;
        rep(i,0,n-2) {
            if(s[i]!=s[i+1]) same=false;
            if(s[i]=='B'&&s[i+1]=='B') found=true;
        }
        int stc=0,enc=0;
        if(s[0]=='B') stc=0;
        else{
            int i=0;
            while(s[i+1]=='A') i++;
            stc=i+1;
        }
        if(s[n-1]=='B') enc=0;
        else{
            int i=n-1;
            while(s[i-1]=='A') i--;
            enc=n-i;
        }
        if(stc==0||enc==0||found) {
            int ans=0;
            rep(i,0,n-1) ans+=s[i]=='A';
            cout<<ans<<endl;
        }else{
            int ans=0;
            rep(i,0,n-1) ans+=s[i]=='A';
            ans-=min(stc,enc);
            cout<<ans<<endl;
        }
    }
    return 0;
}