#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=2e3+10;
int _,a,b,n,t[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>a>>b>>n;
        rep(i,1,n) cin>>t[i];
        long long ans=b;
        rep(i,1,n) ans+=min(a-1,t[i]);
        cout<<ans<<endl;
    }
    return 0;
}