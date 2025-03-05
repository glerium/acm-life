#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e3+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5] = {}, f[2][maxn+7] = {};
    rep(i,1,n) cin >> a[i];
    int ans = 0;
    int ff[2] = {};
    ff[0] = 1;
    rep(i,1,n) {
        int gg[2] = {ff[0], ff[1]};
        rep(j,0,1) {
            gg[(j + a[i]) & 1] += ff[j];
        }
        ff[0] = gg[0] % mod;
        ff[1] = gg[1] % mod;
    }
    ans = ff[0] - 1;
    rep(i,1,n) {
        memset(f, 0, sizeof(f));
        f[a[i] & 1][0] = 1;
        rep(j,1,n) {
            if(a[j] >= a[i])
                continue;
            for(int k=a[i]-a[j]-1; k>=0; k--) {
                rep(l,0,1) {
                    f[(l+a[j])&1][k+a[j]] += f[l][k];
                    f[(l+a[j])&1][k+a[j]] %= mod;
                }
            }
        }
        rep(j,0,a[i]-1) {
            ans = ((ans - f[0][j]) % mod + mod) % mod;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
