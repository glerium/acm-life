#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    vector<int> d(n+5);
    rep(i,1,n-1) {
        int x,y; cin >> x >> y;
        d[x]++; d[y]++;
    }
    ll ans = 1;
    rep(i,1,n) {
        // cout << d[i] << ' ';
        if(d[i] % 2 == 0)
            d[i] --;
        for(int j=d[i];j>=1;j-=2) {
            ans *= j % mod;
            ans %= mod;
        }
    }
    // cout << endl;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}