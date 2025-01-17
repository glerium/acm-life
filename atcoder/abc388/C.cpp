#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5] = {};
    rep(i,1,n) cin >> a[i];
    ll ans = 0;
    rep(i,1,n) {
        int idx = lower_bound(a+i, a+1+n, a[i] * 2) - a;
        // cerr << n - idx + 1 << endl;
        if(idx != n + 1)
            ans += n - idx + 1;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}