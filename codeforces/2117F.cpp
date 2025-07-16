#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 1e9+7;
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
    vector<vector<int>> g(n+5);
    vector<int> d(n+5);
    rep(i,1,n-1) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        d[x]++; d[y]++;
    }
    vector<int> leaves;
    rep(i,2,n) {
        if(d[i] == 1)
            leaves.push_back(i);
    }
    if(leaves.size() > 2) {
        cout << 0 << endl;
        return;
    } else if(leaves.size() == 1) {
        ll ans = 1;
        rep(i,1,n) ans = (ans * 2) % mod;
        cout << ans << endl;
        return;
    }
    int mid = -1;
    if(d[1] > 1) mid = 1;
    else {
        rep(i,2,n) {
            if(d[i] > 2)
                mid = i;
        }
    }
    vector<int> dep(n+5);
    function<void(int,int)> dfs = [&](int x, int from) {
        // cout << x << ' ' << from << endl;
        dep[x] = dep[from] + 1;
        for(auto i : g[x]) {
            if(i == from)
                continue;
            dfs(i, x);
        }
    };
    dfs(1, 0);
    // cout << "ok" << endl;
    ll ans = 1;
    rep(i,1,dep[mid]) ans = (ans * 2) % mod;
    int len1 = dep[leaves[0]] - dep[mid],
        len2 = dep[leaves[1]] - dep[mid];
    // len1: 1; len2: 2
    ll ans1 = 1, ans2 = 1;
    int lim = -1;
    if(len1 == 1) {
        lim = len2 - 1;
    } else if(len1 < len2) {
        lim = len2 - len1;
    } else {
        lim = len1 - len2 - 1;
    }
    rep(i,1,lim) ans1 = (ans1 * 2) % mod;
    swap(len1, len2);

    if(len1 == 1) {
        lim = len2 - 1;
    } else if(len1 < len2) {
        lim = len2 - len1;
    } else {
        lim = len1 - len2 - 1;
    }
    rep(i,1,lim) ans2 = (ans2 * 2) % mod;
    // cout << len1 << ' ' << len2 << ' ' << ans1 << ' ' << ans2 << endl;
    ans = (ans * ((ans1 + ans2) % mod)) % mod;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}