#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
template<class T, class... Arg>
auto Vec(size_t n, Arg... args) {
    if constexpr(sizeof...(args) == 1) {
        return vector<T>(n, args...);
    }else{
        return vector(n, Vec<T>(args...));
    }
}
void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n+5);
    vector<int> p(n+5); 
    rep(i,2,n) {
        cin >> p[i];
        a[p[i]].push_back(i);
    }

    vector<int> d(n+5);
    function<void(int,int)> dfs = [&](int x, int fa) {
        d[x] = d[fa] + 1;
        for(auto i : a[x]) {
            if(i == fa) continue;
            dfs(i, x);
        }
    };
    dfs(1, 0);

    vector<vector<int>> ld(n+5);
    int maxd = 0;
    rep(i,1,n) ld[d[i]].push_back(i);
    rep(i,1,n) maxd = max(maxd, d[i]);

    vector<ll> ans(n+5);
    ans[1] = 1;
    vector<ll> sad(n+5);
    sad[1] = 1;
    for(auto i : ld[2]) {
        ans[i] = 1;
        sad[2]++;
    }
    rep(i,3,maxd) {
        for(auto j : ld[i]) {
            ans[j] = ((sad[d[j] - 1] - ans[p[j]]) % mod + mod) % mod;
            sad[d[j]] += ans[j];
            sad[d[j]] %= mod;
        }
    }
    ll out = 0;
    rep(i,1,n) {
        out += ans[i];
        out %= mod;
    }
    cout << out << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
