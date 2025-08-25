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
    vector<int> a(n+5), b(n+5);
    rep(i,1,n) cin >> a[i] >> b[i];
    auto check = [&](ll x) -> bool {
        ll xmin = 0, xmax = 1e9, ymin = 0, ymax = 1e9;
        rep(i,1,n) {
            xmin = max(xmin, a[i] - x);
            xmax = min(xmax, a[i] + x);
            ymin = max(ymin, b[i] - x);
            ymax = min(ymax, b[i] + x);
        }
        if(xmin <= xmax && ymin <= ymax)
            return true;
        else
            return false;
    };
    ll l = 0, r = 3e9, mid, ans = -1;
    while(l <= r) {
        mid = l + r >> 1;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}