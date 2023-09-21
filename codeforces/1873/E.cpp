#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define int long long
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int t,n,x;
ll a[maxn];
string s;
bool check(int xx) {
    ll used=0;
    rep(i,1,n) {
        if(a[i]<xx)
            used+=xx-a[i];
    }
    if(used<=x) return true;
    return false;
}
signed main() {
    cin>>t;
    while(t--) {
        cin>>n>>x;
        rep(i,1,n) cin>>a[i];
        int l=0,r=5e9,mid,ans;
        while(l<=r) {
            mid=l+r>>1;
            if(check(mid)) {
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}