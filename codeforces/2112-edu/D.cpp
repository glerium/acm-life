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
    vector<vector<int>> a(n+5);
    vector<int> d(n+5), du(n+5);
    vector<pair<int,int>> ans;
    rep(i,1,n-1) {
        int x, y; cin >> x >> y;
        ans.push_back({x,y});
        a[x].push_back(y);
        a[y].push_back(x);
        du[x]++; du[y]++;
    }
    function<void(int,int)> dfs = [&](int x, int fa) {
        d[x] = d[fa] + 1;
        for(auto y : a[x]) {
            if(y == fa) continue;
            dfs(y, x);
        }
    };
    dfs(1, 0);
    for(auto &[x,y] : ans) {
        if(d[x] & 1) swap(x, y);
        // d[x] % 2 == 0 && d[y] % 2 == 1
    }
    for(auto &[x,y] : ans) {
        if(du[x] == 2 && du[y] == 1 || du[x] == 1 && du[y] == 2) {
            swap(x, y);
            cout << "YES" << endl;
            for(auto [x,y] : ans)
                cout << x << ' ' << y << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}