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
    int n,t; double p;
    cin >> n >> p >> t;
    auto f = Vec<double>(t+5, n+5, 0);
    f[0][0] = 1;
    rep(i,1,t) {
        rep(j,0,n) {
            if(j == n)
                f[i][j] = f[i-1][j-1] * p + f[i-1][j];
            else
                f[i][j] = f[i-1][j] * (1 - p) + (j-1 >= 0 ? f[i-1][j-1] * p : 0);
            // cout << f[i][j] << ' ';
        }
        // cout << endl;
    }
    double ans = 0;
    rep(i,1,n)
        ans += f[t][i] * i;
    cout << fixed << setprecision(7) << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}