#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    vector<int> a(n+5), b(n+5);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    int ans = 0;
    a[0] = 1;
    a[n+1] = 1;
    rep(i,1,n) {
        int g1 = gcd(a[i-1], a[i]);
        int g2 = gcd(a[i], a[i+1]);
        ll l = (ll)g1 * g2 / gcd(g1, g2);
        if(a[i] > l) ans++;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}