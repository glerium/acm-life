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
    ll ans = 0;
    rep(i,1,n) ans += a[i];
    ll ct = 1;
    ll lct = 0, rct = 0;
    rep(i,1,n) {
        if(a[i] == 0)
            lct++;
        else
            break;
    }
    for(int i=n;i>=1;i--) {
        if(a[i] == 0)
            rct++;
        else
            break;
    }
    if(lct == n) {
        ct *= 1ll * n * (n + 1) / 2;
        ct %= mod;
    } else {
        ct *= 1ll * (lct + 1) * (rct + 1);
        ct %= mod;
    }
    int mx = -inf, mi = inf;
    rep(i,1,n) {
        if(a[i] == 0) continue;
        mx = max(mx, a[i]);
        mi = min(mi, a[i]);
    }
    if(mx == -inf) {
        ct *= 1ll * (n+1) * (n+1) % mod;
        ct %= mod;
    } else {
        ct *= mi - (-n) + 1;
        ct %= mod;
        ct *= n - mx + 1;
        ct %= mod;
    }
    cout << ans << ' ' << ct << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}