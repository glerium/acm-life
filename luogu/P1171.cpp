#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int d[n][n];
    rep(i,0,n-1) rep(j,0,n-1) cin >> d[i][j];
    int f[1<<n][n];
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for(int i=0;i<(1<<n);i++) {
        for(int j=0;j<n;j++) {
            if(!(i & (1<<j)))
                continue;
            for(int k=0;k<n;k++) {
                if(k == j)
                    continue;
                if(!(i & (1 << k)))
                    continue;
                f[i][j] = min(f[i][j], f[i^(1<<j)][k] + d[k][j]);
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for(int i=0;i<n;i++)
        ans = min(ans, f[(1<<n)-1][i] + d[i][0]);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
