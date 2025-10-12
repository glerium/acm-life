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
    string s; cin >> s;
    s = ' ' + s;
    map<int,vector<int>> mp;
    vector<int> f(n+5);
    mp[0].push_back(0);
    rep(i,1,n) {
        f[i] = f[i-1] + (s[i] == 'a') - (s[i] == 'b');
        mp[f[i]].push_back(i);
    }
    int ans = 114514 * 2;
    rep(r,1,n) {
        // cout << f[r] << ' ' << f[n] << endl;
        auto fnd = lower_bound(mp[f[r] - f[n]].begin(), mp[f[r] - f[n]].end(), r);
        if(fnd == mp[f[r] - f[n]].begin()) continue;
        ans = min(ans, r - *prev(fnd));
    }
    if(f[n] == 0) ans = 0;
    if(ans >= n) cout << -1 << endl;
    else cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}