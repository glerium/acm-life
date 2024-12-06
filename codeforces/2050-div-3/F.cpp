#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e6+10;
constexpr ll mod = 998244353;
int f[maxn][20] = {};
int mf[maxn][20] = {};
void solve() {
    int n,q; cin >> n >> q;
    int a[n+5] = {};
    rep(i,1,n) cin >> a[i];
    int b[n+5] = {};
    rep(i,2,n) b[i] = a[i] - a[i-1];
    rep(i,1,n) f[i][0] = b[i];
    rep(i,1,n) mf[i][0] = a[i];
    rep(j,1,18) {
        rep(i,1,n) {
            // if(i == 2 &&j  == 2) {
            //     cout << "tee" << i+(1<<(j-1));
            //     cout << mf[i][j-1] << ' ' << mf[i+(1<<(j-1))][j-1] << endl;
            // }
            f[i][j] = gcd(f[i][j-1], f[i+(1<<(j-1))][j-1]);
            mf[i][j] = max(mf[i][j-1], mf[i+(1<<(j-1))][j-1]);
            // cout << mf[i][j] << ' ';
        }
        // cout << endl;
    }
    while(q--) {
        int l, r; cin >> l >> r;
        int ml = l, mr = r;
        l++;
        int ans = 0;
        int mx = 0;
        for(int i=18;i>=0;i--) {
            if(l + (1<<i) - 1 > r)
                continue;
            ans = gcd(ans, f[l][i]);
            l += 1<<i;
        }
        // cout << ":" << mf[2][1] << mf[4][1] << mf[2][2] << ';' << endl;
        for(int i=18;i>=0;i--) {
            if(ml + (1<<i) - 1 > mr)
                continue;
            mx = max(mx, mf[ml][i]);
            ml += 1<<i;
        }
        // cout << endl << ans << ' ' << mx << endl;
        if(ans == mx) cout << 0 << ' ';
        else cout << ans << ' ';
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
