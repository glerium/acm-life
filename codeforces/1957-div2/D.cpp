#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5]; rep(i,1,n) cin >> a[i];
    int s[n+5]; rep(i,1,n) s[i] = s[i-1] ^ a[i];
    ll ans = 0;
    // rep(i,1,n) if(s[i] < s[i-1]) ans++;
    int ctl[40] = {}, ctr[40] = {};
    rep(i,0,n) {
        rep(j,0,31)
            ctr[j] += !bool(s[i] & (1ll<<j));
    }
    // rep(j,0,31) ctl[j]++;
    auto maxbit = [&](int x) {
        for(int i=31;i>=0;i--)
            if(x & (1 << i))
                return i;
        return 0;
    };
    rep(i,1,n) {
        rep(j,0,31) {
            ctl[j] += !bool(s[i-1] & (1ll << j));
            ctr[j] -= !bool(s[i-1] & (1ll << j));
        }
        int mb = maxbit(a[i]);
        int lcnt = i, rcnt = n-i+1;
        ans += 1ll * ctl[mb] * ctr[mb] + 1ll * (lcnt - ctl[mb]) * (rcnt - ctr[mb]);
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}