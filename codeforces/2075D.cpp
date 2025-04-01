#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll f[207][207][207] = {};
    memset(f, 0x3f, sizeof(f));
    f[0][0][0] = 0;
    for(int i=1;i<=60;i++) {
        for(int j=0;j<=60;j++) {
            for(int k=0;k<=60;k++) {
                f[i][j][k] = min(f[i][j][k], f[i-1][j][k]);
                f[i][j+i][k] = min(f[i][j+i][k], f[i-1][j][k] + (1ll << i));
                f[i][j][k+i] = min(f[i][j][k+i], f[i-1][j][k] + (1ll << i));
            }
        }
    }
    ll g[107][107] = {};
    memset(g, 0x3f, sizeof(g));
    rep(i,0,60) rep(j,0,60) rep(k,0,60) g[j][k] = min(g[j][k], f[i][j][k]);
    int t; cin >> t;
    while(t--) {
        ll x, y; cin >> x >> y;
        ll ans = LLONG_MAX;
        rep(i,0,60) rep(j,0,60) {
            if((x >> i) == (y >> j)) {
                ans = min(ans, g[i][j]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}