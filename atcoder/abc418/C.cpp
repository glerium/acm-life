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
    int n,q; cin >> n >> q;
    vector<int> a(n+5); rep(i,1,n) cin >> a[i];
    sort(a.begin() + 1, a.begin() + 1 + n);
    int mx = *max_element(a.begin() + 1, a.begin() + 1 + n);
    vector<ll> s(n+5);
    rep(i,1,n) s[i] = s[i-1] + a[i];
    ll sall = s[n];
    while(q--) {
        int x; cin >> x;
        if(x > mx) cout << -1 << endl;
        else {
            int fnd = lower_bound(a.begin(), a.begin() + 1 + n, x) - a.begin() - 1;
            ll ret = s[fnd] + 1ll * (n - fnd) * (x - 1) + 1;
            cout << ret << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}