#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[3][n+5] = {};
    rep(i,1,2) rep(j,1,n) cin >> a[i][j];
    ll sum = 0;
    rep(i,1,n) sum += max(a[1][i], a[2][i]);
    ll ans = -1e9;
    rep(i,1,n) ans = max(ans, sum + min(a[1][i], a[2][i]));
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
