#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
int t,n,m;
ll a[maxn],b[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        ll ans = LLONG_MAX, ima = 0;
        for(int i=m+1;i<=n;i++)
            ima += min(a[i], b[i]);
        for(int i=m;i>=1;i--) {
            ans = min(ans, ima + a[i]);
            ima += min(a[i], b[i]);
        }
        cout << ans << endl;
    }
    return 0;
}