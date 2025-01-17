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
    int sum = 0;
    for(int i=1;i<=n;i++) sum += a[i];
    bool f[n+5][sum + 5] = {};
    int fa[n+5][sum + 5] = {};
    f[0][sum] = true;
    rep(i,1,n) {
        int now = a[i];
        while(true) {
            for(int j=sum;j>=0;j--) {
                if(!f[i-1][j]) continue;
                if(j - (a[i] - now) < 0) break;
                f[i][j - (a[i] - now)] = true;
                fa[i][j - (a[i] - now)] = j;
                // cout << i << ' ' << j - (a[i] - now) << endl;
            }
            if(!now) break;
            now /= 2;
        }
    }
    int now = 100000;
    // for(int i=n;i>=1;i--) {
    //     cout << i << ' ' << fa[i][now] << endl;
    //     now = fa[i][now];
    // }
    if(!f[n][100000]) {
        cout << -1 << endl;
    } else {
        int ans[n+5] = {};
        int now = 100000;
        for(int i=n;i>=1;i--) {
            int delta = fa[i][now] - now;
            int nowi = a[i];
            while(a[i] - nowi != delta) {
                nowi /= 2;
                ans[i]++;
            }
            now = fa[i][now];
        }
        rep(i,1,n) cout << ans[i] << ' ';
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
