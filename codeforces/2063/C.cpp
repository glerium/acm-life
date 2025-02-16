#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    vector<int> a[n+5];      // to
    rep(i,1,n-1) {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    set<int> del;

    int mx = 0, mxi;
    rep(i,1,n) {
        if(mx < a[i].size()) {
            mx = a[i].size();
            mxi = i;
        }
    }
    del.insert(mxi);
    
    mx = -1;
    mxi = -1;
    rep(i,1,n) {
        if(del.count(i)) continue;
        int ct = 0;
        for(auto to : a[i]) {
            if(!del.count(to))
                ct++;
        }
        if(mx < ct) {
            mx = ct;
            mxi = i;
        }
    }
    del.insert(mxi);

    bool vis[n+5] = {};
    function<void(int)> dfs = [&](int x) -> void {
        // if(vis[x]) return;
        vis[x] = true;
        for(auto to : a[x]) {
            if(vis[to] || del.count(to)) continue;
            dfs(to);
        }
    };

    int ans = 0;
    rep(i,1,n) {
        if(vis[i]) continue;
        if(del.count(i)) continue;
        dfs(i);
        ans++;
    }

    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
