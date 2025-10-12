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
    int n; cin >> n;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    auto b = a;
    ll ans = 1e15;
    auto dp = [&](vector<int>& a) -> ll {
        vector<ll> f(n+5, 1e15);
        f[0] = 0;
        rep(i,2,n) {
            f[i] = min(f[i], f[i-2] + max(a[i], a[i-1]) - min(a[i], a[i-1]));
            if(i >= 3) {
                int mid = 0ll + a[i] + a[i-1] + a[i-2] - max({a[i], a[i-1], a[i-2]}) - min({a[i], a[i-1], a[i-2]});
                f[i] = min(f[i], f[i-3] + abs(a[i] - mid) + abs(a[i-1] - mid) + abs(a[i-2] - mid));
            }
        }
        return f[n];
    };
    ans = dp(b);

    rep(_,1,3) {   
        b[0] = b[1];
        rep(i,1,n-1) b[i] = b[i+1];
        b[n] = b[0];
        ans = min(ans, dp(b));
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