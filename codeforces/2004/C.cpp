#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    ll n,k; cin>>n>>k;
    ll a[n+5]; rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    ll ans=0;
    for(int i=1;i<=n;i++) {
        if(i&1) ans += a[i];
        else ans -= a[i];
    }
    cout << max(0ll, ans - k) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
