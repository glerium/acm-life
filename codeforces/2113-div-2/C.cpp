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
    int n,m,k; cin >> n >> m >> k;
    vector<string> a(n+5);
    rep(i,1,n) {
        cin >> a[i];
        a[i] = ' ' + a[i];
    }
    auto f = Vec<int>(n+5, m+5, 0);
    rep(i,1,n) rep(j,1,m)
        f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + (a[i][j] == 'g');
    int sum = f[n][m];
    int ans = 0;
    auto get = [&](int x1, int y1, int x2, int y2) -> int {
        // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
        return f[x2][y2] - f[x2][y1-1] - f[x1-1][y2] + f[x1-1][y1-1];
    };
    rep(i,1,n) rep(j,1,m) {
        if(a[i][j] != '.') continue;
        int tmp = get(max(1, i-k+1), max(1, j-k+1), min(i+k-1, n), min(j+k-1, m));
        ans = max(ans, sum - tmp);
        // cout << i << ' ' << j << ' ' << tmp << endl;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
