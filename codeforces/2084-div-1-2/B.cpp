#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    ll a[n+5] = {};
    rep(i,1,n) cin >> a[i];
    sort(a+1, a+1+n);
    ll mn = a[1];
    ll g = 0;
    rep(i,2,n) {
        if(a[i] % mn == 0) {
            g = gcd(g, a[i]);
        }
    }
    cout << (g == mn ? "Yes" : "No") << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
