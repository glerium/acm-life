#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 1e9+7;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void solve() {
    int x,y; cin >> x >> y;
    int n = sqrt(x + y) * 2;
    auto f = Vec<int>(2, x + 5, 0);
    f[0][0] = 1;
    ll ans = 0;
    rep(i,1,n) {
        const ll tot = i * (i + 1) / 2;
        fill(f[i&1].begin(), f[i&1].end(), 0);
        rep(j,0,x) {
            if(tot - j < 0 || tot - j > y) continue;
            if(j - i >= 0) {                    // use x
                f[i&1][j] += f[!(i&1)][j - i];
            }
            f[i&1][j] %= mod;
            if(tot - j <= y) {    // use y
                f[i&1][j] += f[!(i&1)][j];
            }
            f[i&1][j] %= mod;
        }
        if(accumulate(f[i&1].begin(), f[i&1].end(), 0ll) != 0) {
            ans = accumulate(f[i&1].begin(), f[i&1].end(), 0ll) % mod;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}