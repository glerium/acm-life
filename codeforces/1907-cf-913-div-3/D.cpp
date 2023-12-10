#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=2e5+10;
int t,n,l[maxn],r[maxn];
bool check(int k) {
    int le=0,ri=1e9;
    for(int i=n;i>=1;i--) {
        if(le>r[i]||ri<l[i])
            return false;
        le=max(le,l[i]);
        ri=min(ri,r[i]);
        le=max(0,le-k);
        ri=min(ri+k,int(1e9));
        // cout<<":"<<le<<' '<<ri<<endl;
    }
    if(le>0) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        rep(i,1,n) cin>>l[i]>>r[i];
        int l=0,r=1e9,mid,ans;
        while(l<=r) {
            mid=(l+r)/2;
            if(check(mid)) {
                ans=mid;
                r=mid-1;
            }else {
                l=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}