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
    ll n,m; cin >> n >> m;
    ll mi = (n - m + 1) * (n - m) / 2;
    ll mx = 0;
    ll k = n / m;
    mx += (n - k * m) * (k + 1) * k / 2;
    mx += (m - (n - k * m)) * (k - 1) * k / 2;
    cout << mx << ' ' << mi << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}