#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll INF = 0x3f3f3f3f;
void solve() {
    int n; cin >> n;
    vector<ll> a(n+5), f1(n+5), f2(n+5);
    vector<int> d(n+5);
    rep(i,1,n) cin >> a[i];
    vector<vector<int>> g(n+5);
    rep(i,1,n-1) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    function<void(int,int,int,vector<ll>&)> dfs = [&](int x, int fa, int sign, vector<ll>& f) {
        f[x] = max(0ll, f[fa] + sign * a[x]);
        d[x] = d[fa] + 1;
        for(auto v : g[x]) {
            if(v == fa) continue;
            dfs(v, x, -sign, f);
        }
    };
    dfs(1, 0, 1, f1);
    dfs(1, 0, -1, f2);
    rep(i,1,n) {
        if(d[i] % 2 == 1) {
            cout << f1[i] << ' ';
        } else {
            cout << f2[i] << ' ';
        }
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
