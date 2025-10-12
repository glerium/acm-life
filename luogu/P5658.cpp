#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 1145141919810;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void solve() {
    int n; cin >> n;
    string s; cin >> s; s = ' ' + s;
    vector<vector<int>> a(n+5);
    vector<int> fa(n+5);
    rep(i,2,n) {
        int x; cin >> x;
        a[x].push_back(i);
        fa[i] = x;
    }
    map<int,int> mp;
    vector<ll> ans(n+5), f(n+5);
    auto dfs = [&](auto&& dfs, int x) -> void {
        ans[x] = ans[fa[x]];
        f[x] = f[fa[x]] + (s[x] == '(' ? 1 : -1);
        if(f[x] >= 0) {
            ans[x] += mp[f[x]];
        } else {
            f[x] = -1145141919810;
        }
        mp[f[x]]++;
        for(auto v : a[x])
            dfs(dfs, v);
        mp[f[x]]--;
    };
    mp[0] = 1;
    dfs(dfs, 1);
    ll ret = 0;
    rep(i,1,n) cout << ans[i] << endl;
    rep(i,1,n) ret ^= i * ans[i];
    cout << ret << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}