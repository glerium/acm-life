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
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    auto f = Vec<int>(n+5, n+5, -1);
    rep(i,1,n) f[i][i] = a[i];
    auto dp = [&](auto &&dp, int l, int r) -> int {
        if(f[l][r] != -1) return f[l][r];
        rep(i,l,r-1) {
            int x = dp(dp,l,i), y = dp(dp,i+1,r);
            if(x == y && x != -2) {
                f[l][r] = max(f[l][r], x + 1);
            }
        }
        if(f[l][r] == -1) f[l][r]--;
        return f[l][r];
    };
    int ans = 0;
    rep(i,1,n) rep(j,i,n) {
        ans = max(ans, dp(dp,i,j));
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