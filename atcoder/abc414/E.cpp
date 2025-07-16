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
    ll ans = 0;
    if(n % 2 == 0) ans += n / 2 % mod * (n - 1) % mod;
    else ans += (n - 1) / 2 % mod * n % mod;
    ans %= mod;
    ll curbegin = 1;
    while(curbegin <= n) {
        ll curct = n / curbegin;
        ll curend = n / curct;
        ll len = (curend - curbegin + 1) % mod;
        ans -= (curct - 1) % mod * len % mod;
        ans = (ans % mod + mod) % mod;
        curbegin = curend + 1;
    }
    cout << ans % mod << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}