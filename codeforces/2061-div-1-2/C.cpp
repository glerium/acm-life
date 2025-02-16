#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5] = {};
    rep(i,1,n) cin >> a[i];
    ll f[n+5][2] = {};
    if(a[1] == 0)
        f[1][0] = f[1][1] = 1;
    else
        f[1][1] = 1;
    rep(i,2,n) {
        if(a[i] == a[i-1]) 
            f[i][0] += f[i-1][0];
        if(a[i] == a[i-2] + 1)
            f[i][0] += f[i-1][1];
        f[i][1] += f[i-1][0];
        f[i][0] %= mod;
        f[i][1] %= mod;
    }
    cout << (f[n][1] + f[n][0]) % mod << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
