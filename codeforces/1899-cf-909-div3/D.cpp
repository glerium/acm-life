#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=2e5+10;
int t,n,a[maxn];
map<int,int> ct;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        ct.clear();
        rep(i,1,n) ct[a[i]]++;
        long long ans=0;
        for(auto i:ct) {
            int wzl=i.second;
            if(wzl>1) ans+=1ll*wzl*(wzl-1)/2;
        }
        if(ct.count(1)&&ct.count(2)) ans+=1ll*ct[1]*ct[2];
        cout<<ans<<endl;
    }
}