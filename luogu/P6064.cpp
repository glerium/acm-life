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
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    auto f = Vec<int>(2, m+5, 2, -INT_MAX);
    // f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1])
    // f[i][j][1] = max(f[i-1][j-1][0], f[i-1][j-1][1] + a[i])
    
    auto dp = [&]() {
        rep(i,1,n) {
            if(i != 1) f[i&1][0][0] = 0;
            rep(j,1,m) {
                if(i == 1 && j == 1) continue;
                f[i&1][j][0] = max(f[!(i&1)][j][0], f[!(i&1)][j][1]);
                f[i&1][j][1] = max(f[!(i&1)][j-1][0], f[!(i&1)][j-1][1] + a[i]);
            }
        }
    };
    f[1][0][0] = f[1][1][1] = 0;
    dp();
    int ans = max(f[n&1][m][0], f[n&1][m][1]);

    f = Vec<int>(2, m+5, 2, -INT_MAX);
    f[1][0][0] = 0;
    f[1][1][1] = a[1];
    dp();
    ans = max(ans, f[n&1][m][1]);

    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}