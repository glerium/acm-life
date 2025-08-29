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
    vector<int> a(2*n+5);
    rep(i,1,n) cin >> a[i];
    rep(i,n+1,2*n) a[i] = a[i-n];
    auto f = Vec<int>(2*n+5, 2*n+5, -1);
    // f[l][r] = max(f[l][k] + f[k+1][r+1] + a[l]*a[k+1]*a[r+1])
    function<int(int,int)> dp = [&](int l, int r) {
        if(f[l][r] != -1) return f[l][r];
        int ans = 0;
        rep(k,l,r-1) {
            ans = max(ans, dp(l,k) + dp(k+1,r) + a[l]*a[k+1]*a[r+1]);
        }
        return f[l][r] = ans;
    };
    int ans = 0;
    rep(i,1,n) ans = max(ans, dp(i,i+n-1));
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}