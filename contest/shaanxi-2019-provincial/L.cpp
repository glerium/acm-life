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
ll get(ll x) {
    if(x == 0) return 0;
    ll ans = 1;
    while(x) {
        ans *= x % 10;
        x /= 10;
    }
    return ans;
}
void solve() {
    ll l,r; cin >> l >> r;
    if(r - l > 10) {
        cout << 0 << endl;
    } else {
        ll ans = 1;
        rep(i,l,r) {
            ans *= get(i);
            ans %= mod;
        }
        cout << ans << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}