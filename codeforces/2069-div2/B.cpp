#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
void solve() {
    int n,m; cin >> n >> m;
    constexpr int to[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int a[n+5][m+5] = {};
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    int ans = 0, mx = 0;
    map<int,int> mp;
    rep(i,1,n) rep(j,1,m) {
        if(!mp.count(a[i][j]))
            mp[a[i][j]] = 1;
        rep(k,0,3) {
            int ti = i + to[k][0], tj = j + to[k][1];
            if(ti > 0 && ti <= n && tj > 0 && tj <= m && a[i][j] == a[ti][tj]) {
                mp[a[i][j]] = 2;
            }
        }
    }
    for(auto [k,v] : mp) {
        ans += v;
        mx = max(mx, v);
    }
    cout << ans - mx << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}