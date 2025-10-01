#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void solve() {
    int n,W; cin >> n >> W;
    vector<int> a(n+5), b(n+5);
    rep(i,1,n) cin >> b[i] >> a[i];
    auto check = [&](double x) -> bool {
        vector<double> pr(n+5);
        rep(i,1,n) pr[i] = a[i] - x * b[i];
        auto &w = b;
        auto f = Vec<double>(n+5, W+5, -INFINITY);
        f[0][0] = 0;
        rep(i,1,n) {
            for(int j=W;j>=0;j--) {
                f[i][j] = max(f[i][j], f[i-1][j]);
                f[i][min(W, j+w[i])] = max({f[i][min(W, j+w[i])], f[i-1][min(W, j+w[i])], f[i-1][j] + pr[i]});
            }
        }
        return f[n][W] >= 0;
    };
    double l = 0, r = 1145141919810, mid;
    while(r - l >= 1e-6) {
        mid = (l + r) / 2;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int ans = 1000 * (mid + 1e-6);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}