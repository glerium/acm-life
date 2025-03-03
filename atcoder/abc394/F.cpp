#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5] = {}, b[n+5] = {};
    int de[n+5] = {};
    bool ok[n+5] = {};
    rep(i,1,n-1) {
        cin >> a[i] >> b[i];
        de[a[i]]++; de[b[i]]++;
    }
    rep(i,1,n) {
        ok[i] = (de[i] >= 4);
    }
    vector<vector<int>> p(n+5);
    rep(i,1,n-1) {
        if(ok[a[i]] && ok[b[i]]) {
            p[a[i]].push_back(b[i]);
            p[b[i]].push_back(a[i]);
        }
    }
    vector<bool> vis(n+5, false);
    function<int(int, int)> dfs = [&](int x, int fa) -> int {
        int sz = 1;
        vector<int> vret;
        for(auto i : p[x]) {
            if(!vis[i]) {
                vis[i] = true;
                vret.push_back(dfs(i, x));
            }
        }
        if(!vret.empty())
            sort(vret.begin(), vret.end(), greater<int>());

        rep(i,0,min(3 - (fa != -1), int(vret.size())-1))
            sz += vret[i];
        return sz;
    };
    int ans = -1;
    rep(i,1,n) {
        if(!vis[i] && ok[i]) {
            vis[i] = true;
            ans = max(ans, dfs(i, -1));
        }
    }
    if(ans == -1)
        cout << -1 << endl;
    else cout << 3 * ans + 2 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
