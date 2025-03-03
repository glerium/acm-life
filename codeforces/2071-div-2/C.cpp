#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,st,en; cin >> n >> st >> en;
    vector<vector<int>> a(n+5);
    rep(i,1,n-1) {
        int x,y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<int> route;
    set<int> stroute;
    vector<int> fa(n+5);
    function<void(int,int)> dfs = [&](int x, int fat) {
        fa[x] = fat;
        for(auto i : a[x]) {
            if(fa[x] == i) continue;
            dfs(i, x);
        }
    };
    dfs(en, 0);
    int now = st;
    // cout << 1 << endl;
    // route.push_back(now);
    while(true) {
        route.push_back(now);
        if(fa[now] == 0) break;
        now = fa[now];   
    }
    // route.push_back(now);
    // cout << "ruote" << endl;
    // for(auto i : route) cout << i << ' ';
    // cout << endl;
    for(auto i : route) stroute.insert(i);
    vector<int> ans;
    function<void(int, int)> dfs2 = [&](int x, int fa) {
        for(auto i : a[x]) {
            if(stroute.count(i) || i == fa)
                continue;
            dfs2(i, x);
        }
        ans.push_back(x);
    };
    for(auto i : route) {
        dfs2(i, 0);
    }
    for(auto i : ans)
        cout << i << ' ';
    cout << endl;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
