#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll mod = 1e9+7;
int t;
void solve() {
    int n,k; cin>>n>>k;
    vector<ll> a(n+5), f(n+5);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) 
        f[i] = max(0ll, f[i-1] + a[i]);
    ll mx = LLONG_MIN;
    for(int i=1;i<=n;i++)
        mx = max(mx, f[i]);
    mx %= mod;
    ll s = 0;
    for(int i=1;i<=k;i++) {
        s = (s + mx) % mod;
        mx = mx * 2 % mod;
    }
    for(int i=1;i<=n;i++)
        s = (s + a[i]) % mod;
    cout << (s + mod) % mod << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}