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
    int n,m; cin >> n >> m;
    auto a = Vec<ll>(n+5, m+5, 0);
    vector<ll> p(n+m+5);
    rep(i,1,n) rep(j,1,m)
        cin >> a[i][j];
    rep(i,1,n+m-1) cin >> p[i];

    auto check = [&](ll x) -> bool {
        auto f = Vec<ll>(n+5, m+5, -inf);
        f[1][0] = f[0][1] = x;
        rep(i,1,n) rep(j,1,m) {
            ll now = max(f[i-1][j], f[i][j-1]);
            now += a[i][j] - p[i+j-1];
            if(now < 0) continue;
            f[i][j] = now;
        }
        if(f[n][m] < 0) return false;
        return true;
    };

    ll l = 0, r = 1e15, mid, ans = -1;
    while(l <= r) {
        mid = l + r >> 1;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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