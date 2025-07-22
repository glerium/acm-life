#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef __int128 i128;
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
ll qpow(ll x, ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return x * qpow(x, y - 1) % mod;
    return qpow(x * x % mod, y / 2);
}
void solve() {
    ll a,b,c,d; cin >> a >> b >> c >> d;
    ll ans = 1;
    ll g = gcd(a, c);
    while(g != 1) {
        if(b < d) {
            swap(b, d);
            swap(a, c);
        }
        ans = ans * qpow(g % mod, d) % mod;
        ll x = a / g, y = c / g;
        auto oa = a, ob = b, oc = c, od = d;
        a = g, b = ob - od, c = y, d = od;
        g = gcd(a, c);
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