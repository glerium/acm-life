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
    // rep(i,1,n) a[i] = rand() + 1;
    sort(a.begin() + 1, a.begin() + 1 + n);
    ll ans = 0;
    int k = n;
    // while(a[k] == a[n]) k--;
    rep(i,1,n) rep(j,i+1,n) {
        auto fnd1 = lower_bound(a.begin() + j + 1, a.begin() + n + 1, - a[i] - a[j] + a[n] + 1) - a.begin();
        auto fnd2 = prev(lower_bound(a.begin() + j + 1, a.begin() + n + 1, a[i] + a[j])) - a.begin();
        int kk = fnd2 - fnd1 + 1;
        ans += max(kk, 0);
    }
    cout << ans << endl;
    // rep(i,1,n) rep(j,i+1,n) rep(k,j+1,n) {
    //     // a[k] > a[i] + a[j] - a[n]
    //     // a[k] < a[i] + a[j]
    //     if(a[n] < a[i] + a[j] + a[k] && a[i] + a[j] > a[k]) ans2++;
    // }
    // // if(ans != ans2)
    //     cout << ans << ' ' << ans2 << endl;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
