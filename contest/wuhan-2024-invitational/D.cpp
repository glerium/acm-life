#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
template<class T, class... Args>
auto Vec(size_t n, Args... arg) {
    if constexpr (sizeof...(arg) == 1) {
        return vector<T>(n, arg...);
    }else{
        return vector(n, Vec<T>(arg...));
    }
}
void solve() {
    int n; cin >> n;
    vector<ll> a(n+5);
    rep(i,1,n) cin >> a[i];
    vector<ll> s(n+5);
    rep(i,1,n) s[i] = s[i-1] + a[i];
    auto querySum = [&](int l, int r) {
        return s[r] - s[l-1];
    };
    auto g = Vec<ll>(n+5, 2*n+5, 0ll);
    rep(i,1,n) rep(j,1,2*n) {
        int l = max(1, i-j),
            r = min(n, i+j);
        g[i][j] = max(querySum(l, i), querySum(i, r));
    }
    auto f1 = Vec<ll>(2, 3*n+5, 0ll),
         f2 = Vec<ll>(2, 3*n+5, 0ll);
    auto f = Vec<ll>(n+5, 2*n+5, 0ll);
    rep(i,1,n) rep(j,1,2*n) f[i][j] = g[i][j];
    rep(j,1,2*n) {
        rep(i,0,3*n) f1[j&1][i] = 0;
        rep(i,1,n) {
            f1[j&1][i+j] = max(f1[j&1][i+j], g[i][j]);
        }
        rep(i,1,3*n) {
            f1[j&1][i] = max(f1[j&1][i], f1[!(j&1)][i]);
        }
        rep(i,1,n)
            f[i][j] = max(f[i][j], f1[j&1][i+j]);
    }
    rep(j,1,2*n) {
        rep(i,0,3*n) f2[j&1][i] = 0;
        rep(i,1,n) {
            f2[j&1][i-j+2*n] = max(f2[j&1][i-j+2*n], g[i][j]);
        }
        rep(i,1,3*n) {
            f2[j&1][i] = max(f2[j&1][i], f2[!(j&1)][i]);
        }
        rep(i,1,n)
            f[i][j] = max(f[i][j], f2[j&1][i-j+2*n]);
    }
    ll ans = 0;
    rep(i,1,n) {
        ll now = 0;
        rep(j,1,2*n) {
            now ^= j * f[i][j];
        }
        ans ^= i + now;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
