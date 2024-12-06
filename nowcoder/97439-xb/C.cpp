#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5][n+5] = {};
    rep(i,1,n) {
        rep(j,1,n) {
            cin >> a[i][j];
            if(a[i][j])
                a[i][j] /= abs(a[i][j]);
        }
    }
    bool ok = true;
    rep(i,1,n) {
        rep(j,1,n) {
            if(!a[i][j])
                continue;
            if(a[i-1][j] * a[i][j] > 0 || a[i+1][j] * a[i][j] > 0 || a[i][j-1] * a[i][j] > 0 || a[i][j+1] * a[i][j] > 0)
                ok = false;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
