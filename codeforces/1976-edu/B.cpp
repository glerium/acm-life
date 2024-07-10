#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    ll a[n+5]; rep(i,1,n) cin >> a[i];
    ll b[n+5]; rep(i,1,n+1) cin >> b[i];
    ll ans = 1;
    rep(i,1,n) 
        ans += abs(a[i] - b[i]);
    ll delta = 1e9;
    rep(i,1,n) {
        int mi = min(a[i], b[i]);
        int mx = max(a[i], b[i]);
        if(mi <= b[n+1] && b[n+1] <= mx) delta = min(delta, 0ll);
        else if(b[n+1] < mi) delta = min(delta, mi - b[n+1]);
        else delta = min(delta, b[n+1] - mx);
    }
    ans += delta;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

