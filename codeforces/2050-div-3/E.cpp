#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    string a, b, c; cin >> a >> b >> c;
    int na = a.size(), nb = b.size(), nc = c.size();
    a = ' ' + a; b = ' ' + b; c = ' ' + c;
    int f[nc+5][nc+5] = {};
    rep(i,1,nc) {
        f[i][0] = f[i-1][0] + (b[i] != c[i]);
        f[i][i] = f[i-1][i-1] + (a[i] != c[i]); 
        rep(j,1,min(na, i-1)) {
            f[i][j] = min(f[i-1][j] + (b[i-j] != c[i]),
                          f[i-1][j-1] + (a[j] != c[i]));
        }
    }
    cout << f[nc][na] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
