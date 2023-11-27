#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=107;
int t,n;
char s[maxn];
vector<int> w;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>(s+1);
        w.clear();
        int last=-1;
        for(int i=1;i<=n;i++) {
            if(s[i]=='#') {
                if(last!=-1) {
                    w.push_back(i-last);
                    last=-1;
                }
            }else{
                if(last==-1)
                    last=i;
            }
        }
        if(last!=-1) w.push_back(n-last+1);
        bool three=false;
        for(auto i:w) if(i>=3) three=true;
        if(three) cout<<2<<endl;
        else {
            int ans=0;
            for(auto i:w) ans+=i;
            cout<<ans<<endl;
        }
    }
    return 0;
}