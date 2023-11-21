#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=2e5+10;
int t,n,a[maxn],f[maxn];
int getans(int l,int r) {
    if(l>r) return -1e9;
    // cout<<":"<<l<<' '<<r<<endl;
    bool allm=true;
    rep(i,l,r) if(a[i]>=0) allm=false;
    if(allm) {
        int mx=-114514;
        rep(i,l,r) mx=max(mx,a[i]);
        return mx;
    }
    f[l-1]=0;
    int ret=-114514;
    rep(i,l,r) {
        f[i]=max(0,f[i-1]+a[i]);
        ret=max(ret,f[i]);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        int ans=-1e9;
        rep(i,1,n) cin>>a[i];
        int l=1,r=1;
        while(r<=n) {
            if(r==n) {
                if(abs(a[r+1]%2)!=abs(a[r]%2)) ans=max(ans,getans(l,n));
                else {
                    ans=max(ans,getans(l,r));
                    ans=max(ans,a[n]);
                }
            }
            if(abs(a[r+1]%2)!=abs(a[r]%2)) r++;
            else {
                ans=max(ans, getans(l,r));
                if(l!=r) l=r;
                else {
                    ans=max(ans,a[l]);
                    l++,r++;
                }
            }
        }
        if(abs(a[n-1]%2)!=abs(a[n]%2)) ans=max(ans, getans(l,n));
        cout<<ans<<endl;
    }
}