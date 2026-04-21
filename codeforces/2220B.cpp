#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
void solve() {
    int n,m; cin >> n >> m;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    a[0] = -1;
    int mx = 0, now = 0;
    rep(i,1,n) {
        if(a[i] != a[i-1]) {
            mx = max(mx, now);
            now = 1;
        } else {
            now++;
        }
    }
    mx = max(mx, now);
    // cerr << mx << endl;
    if(mx >= m) cout << "NO" << endl;
    else cout << "YES" << endl;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}