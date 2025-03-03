#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,m; cin >> n >> m;
    string s[n+5];
    rep(i,1,n) {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    ll f[5][n+5][m+5] = {};
    ll sx[5][n+5] = {}, sy[5][m+5] = {}, sk[5] = {};
    rep(i,1,n) rep(j,1,m) {
        f[1][i][j] = s[i][j] == '.';
    }
    rep(i,1,n) rep(j,1,m) {
        sx[1][i] += f[1][i][j];
        sy[1][j] += f[1][i][j];
        sk[1] += f[1][i][j];
    }
    rep(k,2,4) {
        rep(i,1,n) rep(j,1,m) {
            if(s[i][j] != '.') continue;
            // sum f[k-1][i1][j1] if i1 == i || j1 == j
            f[k][i][j] = sx[k-1][i] + sy[k-1][j] - 2 * f[k-1][i][j];
        }
        rep(i,1,n) rep(j,1,m) {
            sx[k][i] += f[k][i][j];
            sy[k][j] += f[k][i][j];
            sk[k] += f[k][i][j];
        }
    }
    // rep(i,1,4) cout << sk[i] << endl;
    ll ans = sk[4] - 2 * sk[3] + sk[2];
    ll ssx[n+5] = {}, ssy[m+5] = {};
    rep(i,1,n) rep(j,1,m) {
        ssx[i] += s[i][j] == '.';
        ssy[j] += s[i][j] == '.';
    }
    rep(i,1,n) ans -= ssx[i] * (ssx[i] - 1) * (ssx[i] - 2);
    rep(i,1,m) ans -= ssy[i] * (ssy[i] - 1) * (ssy[i] - 2);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
