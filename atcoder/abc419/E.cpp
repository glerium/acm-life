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
    int n,m,l; cin >> n >> m >> l;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    int sm = 0;
    rep(i,1,l-1) sm += a[i];
    int ans = 0;
    rep(i,l,n) {
        sm += a[i] - a[i - l];
        int target = (sm + m - 1) / m * m;
        int delta = target - sm;
        ans += delta;
        a[i] += delta;
        sm += delta;
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