#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,m; cin >> n >> m;
    int t[n+5] = {}, l[n+5] = {};
    rep(i,1,n) cin >> t[i] >> l[i];
    rep(k,1,m) {
        int ans = 0;
        rep(i,1,n) ans = max(ans, t[i] * (l[i] + k));
        cout << ans << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
