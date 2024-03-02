#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn=1e5+10;
int t,n,a[maxn],q,lt,u;
ll s[maxn];
bool check(int x) {
    if(s[x]-s[lt-1]<=u) return true;
    if(s[x]-s[lt-1]>u&&s[x-1]-s[lt-1]<=u) {
        ll duo=u-(s[x-1]-s[lt-1]);
        ll tig=duo-(a[x]-duo-1);
        if(tig>0) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
        cin>>q;
        while(q--) {
            cin>>lt>>u;
            int l=lt, r=n, mid, ans=l;
            while(l<=r) {
                mid = (l+r)/2;
                // cout<<l<<" "<<mid<<" "<<check(mid)<<endl;
                if(check(mid)) {
                    ans = mid;
                    l = mid + 1;
                }else r = mid - 1;
            }
            cout<<ans<<' ';
        }
        cout<<endl;
    }
    return 0;
}