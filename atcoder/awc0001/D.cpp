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
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(n+5), b(n+5);
    rep(i,1,n) cin >> a[i] >> b[i];
    auto f = Vec<ll>(n+5, m+5, 0ll);
    ll out = 0;
    rep(i,1,n) {
        ll ans = 0;
        rep(j,0,m) {
            if(j-b[i] < 0) continue;
            rep(l,max(0,i-k),i-1) {
                ans = max(ans, f[l][j-b[i]] + a[i]);
            }
            f[i][j] = ans;
            out = max(out, f[i][j]);
        }
    }
    cout << out << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}