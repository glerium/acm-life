#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=3e5+10;
int t,n;
map<int,int> ct;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        ct.clear();
        cin>>n;
        for(int i=1;i<=n;i++) {
            int x; cin>>x;
            ct[x]++;
        }
        long long ans=0;
        long long ch2=0;
        for(auto i=ct.crbegin();i!=ct.rend();i++) {
            int ima=i->second;
            ans+=ima*ch2;
            if(ima>=3) {
                ans+=1ll*ima*(ima-1)*(ima-2)/6;
            }
            if(ima>=2) {
                ch2+=1ll*ima*(ima-1)/2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}