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
    int a[n+5] = {};
    rep(i,1,n) cin >> a[i];
    int len = 0, cur = -1;
    ll ans = 0x3f3f3f3f3f3f3f3f;
    rep(i,1,n) {
        if(cur == -1) {
            cur = a[i];
            len = 1;
        } else if(a[i] == cur) {
            len++;
        } else {
            ans = min(ans, 1ll * (n - len) * cur);
            cur = a[i];
            len = 1;
        }
    }
    ans = min(ans, 1ll * (n - len) * cur);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
