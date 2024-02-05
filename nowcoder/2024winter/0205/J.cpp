#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr int maxn=2e5+10;
int t,n;
ll a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        ll ans=0, done=0;
        for(int i=1;i<=n;i++) {
            if(a[i]<=a[1]*2) {
                ans+=a[i]*4ll*(n-i);
                done+=2ll*(n-i);
            }
        }
        ans+=a[1]*2ll*2*(1ll*(n)*(n-1)-done);
        cout<<ans<<endl;
    }
    return 0;
}
