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
    ll a=0, b=0;
    int ct = 0;
    for(int i=32;i>=0;i--) {
        if((1ll << i) > n) continue;
        if(ct >= 2 && (((1ll << i) & n) == 0)) {
            ans += (1ll << i) * 2;
        } else if(((1ll << i) & n) != 0) {
            ct++;
            ans += (1ll << i);
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}