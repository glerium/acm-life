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
ll qpow(ll x, ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return x * qpow(x, y - 1) % mod;
    return qpow(x * x % mod, y / 2);
}
void solve() {
    int n; cin >> n;
    if(n * (n + 1) / 2 % 2 == 1) {
        cout << 0 << endl;
        return;
    }
    int m = n * (n + 1) / 2;
    vector<int> f(m+5);
    f[0] = 1;
    rep(i,1,n) {
        for(int j=m/2; j>=0; j--) {
            if(j + i > m / 2) continue;
            f[j+i] += f[j];
            f[j+i] %= mod;
        }
    }
    cout << f[m / 2] * qpow(2, mod - 2) % mod << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}