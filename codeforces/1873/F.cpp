#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int t,n,k,a[maxn],h[maxn],s[maxn];
int getans(int l,int r) {
    // printf("::%d %d\n",l,r);
    if(r<l) return -1;
    int ll=l,rr=l,ans=0;
    for(ll=l;ll<=r;ll++) {
        while(s[rr+1]-s[ll-1]<=k&&rr+1<=r) rr++;
        if(s[rr]-s[ll-1]>k) continue;
        ans=max(ans,rr-ll+1);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>k;
        rep(i,1,n) cin>>a[i];
        rep(i,1,n) cin>>h[i];
        rep(i,1,n) s[i]=s[i-1]+a[i];
        int st=1;
        bool in=false;
        int ans=0;
        rep(i,1,n) {
            if(!in) {
                in=true;
            }else{
                if(h[i-1]&&h[i-1]%h[i]==0) continue;
                else {
                    ans=max(ans,getans(st,i-1));
                    st=i;
                }
            }
        }
        if(in) ans=max(ans,getans(st,n));
        cout<<ans<<endl;
    }
    return 0;
}