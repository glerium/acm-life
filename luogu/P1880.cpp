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
    int n; cin >> n;
    vector<int> a(2*n+5), s(2*n+5);
    rep(i,1,n) cin >> a[i];
    rep(i,n+1,2*n) a[i] = a[i-n];
    rep(i,1,2*n) s[i] = s[i-1] + a[i];
    auto f = Vec<int>(2*n+5, 2*n+5, -1);
    auto g = Vec<int>(2*n+5, 2*n+5, 0x3f3f3f3f);
    rep(i,1,2*n) g[i][i] = 0;
    auto rs = [&](int l, int r) -> int {
        return s[r] - s[l-1];
    };
    function<int(int,int)> dp = [&](int l, int r) -> int {
        // f[l][r] = max(f[l][k] + f[k+1][r] + s1 + s2);
        if(f[l][r] != -1) return f[l][r];
        int ans = 0;
        rep(k,l,r-1) ans = max(ans, dp(l,k) + dp(k+1,r) + rs(l, k) + rs(k+1, r));
        return f[l][r] = ans;
    };
    function<int(int,int)> dp2 = [&](int l, int r) -> int {
        // f[l][r] = max(f[l][k] + f[k+1][r] + s1 + s2);
        if(g[l][r] != 0x3f3f3f3f) return g[l][r];
        int ans = INT_MAX;
        rep(k,l,r-1) ans = min(ans, dp2(l,k) + dp2(k+1,r) + rs(l, k) + rs(k+1, r));
        return g[l][r] = ans;
    };
    int ans = 0, ans2 = INT_MAX;
    rep(i,1,n) ans = max(ans, dp(i, i+n-1));
    rep(i,1,n) ans2 = min(ans2, dp2(i, i+n-1));
    cout << ans2 << endl << ans << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}