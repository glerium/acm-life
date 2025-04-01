#pragma GCC optimize(3)

#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
template<class T, class... Arg>
auto Vec(size_t n, Arg... arg) {
    if constexpr (sizeof...(arg) == 1) {
        return vector<T>(n, arg...);
    } else {
        return vector(n, Vec<T>(arg...));
    }
}
void solve() {
    int n,m,p; cin >> n >> m >> p;
    vector<int> a(n+5), b(m+5);
    rep(i,1,n) {
        cin >> a[i];
        a[i] %= p;
    }
    rep(i,1,m) {
        cin >> b[i];
        b[i] %= p;
    }
    auto f = Vec<int>(n+5, m+5, 0);
    auto g = Vec<int>(2, m+5, 1007, -0x3f3f);

    rep(i,1,n) {
        rep(j,1,m) {
            if(a[i] == b[j])
                f[i][j] = max(f[i][j], 1);
            int rr = ((b[j] - a[i]) % p + p) % p;
            int r_ = ((b[j] - a[i] - 1) % p + p) % p;
            int tmp1 = i & 1, tmp2 = !(i&1);
            f[i][j] = max(f[i][j], g[tmp2][j-1][r_] + 1);
            rep(r,0,p-1) {
                if(r == rr)
                    g[tmp1][j][r] = max({g[tmp2][j][r], g[tmp1][j-1][r], f[i][j]});
                else
                    g[tmp1][j][r] = max(g[tmp2][j][r], g[tmp1][j-1][r]);
            }
        }
    }
    int ans = 0;
    rep(i,1,n) rep(j,1,m) ans = max(ans, f[i][j]);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
