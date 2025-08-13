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
    ll n; cin >> n;
    n--;
    ll ans = 0;
    vector<ll> f(100);
    f[0] = 1;
    rep(i,1,60) {
        f[i] = 2 * f[i-1] + (1ll << (i - 1));
    }
    rep(i,0,60) {
        if(n & (1ll << i)) {
            ans += f[i];
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