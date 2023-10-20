#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=1e5+10;
int n,a[maxn],ans=-1;
bitset<maxn> v;
bool all_zero() {
    rep(i,1,n) if(a[i]) return false;
    return true;
}
bool no_zero() {
    rep(i,1,n) if(!a[i]) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n) cin>>a[i];
    if(all_zero()||no_zero()) {
        cout<<0<<endl;
        return 0;
    }
    rep(i,1,n) {
        if(a[i]==0) {
            ans=max(ans,max(a[i-1],a[i+1]));
        }
    }
    v.reset();
    rep(i,1,n) v[a[i]]=true;
    rep(i,1,n) if(!v[i]) {
        ans=max(ans,i);
        break;
    }
    cout<<ans<<endl;
    return 0;
}