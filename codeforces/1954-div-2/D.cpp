#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 5e3+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5]; rep(i,1,n) cin >> a[i];
    int s = 0; rep(i,1,n) s += a[i];
    ll dp[s+5] = {}; dp[0] = 1;
    rep(i,1,n) {
        for(int j=s;j>=a[i];j--) {
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        }
    }
    ll ans = 0;
    rep(i,0,s) ans = (ans + (i+1)/2 * dp[i]) % mod;
    rep(i,1,n) {
        rep(j,0,a[i]-1) {
            ans = (ans + (a[i] - (a[i]+j+1)/2) * dp[j]) % mod;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
