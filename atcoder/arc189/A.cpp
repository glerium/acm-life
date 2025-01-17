#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
ll qpow(ll x, ll y) {
    if(x == 0) return 0;
    if(y == 0) return 1;
    if(y & 1) return x * qpow(x, y-1) % mod;
    return qpow(x * x % mod, y / 2);
}
ll frac(ll x, ll y) {
    return x * qpow(y, mod - 2) % mod;
}
void solve() {
    int n; cin >> n;
    int a[n+5] = {};
    rep(i,1,n) cin >> a[i];
    if(a[1] == 0) {
        cout << 0 << endl;
        return;
    }
    int x[n+5] = {};
    rep(i,1,n-1) x[i] = (a[i] + a[i+1]) % 2;
    vector<pair<int,int>> vct;
    int now = x[1];
    int nowct = 1;
    rep(i,2,n-1) {
        if(x[i] == now) {
            nowct ++;
        }else{
            vct.emplace_back(now, nowct);
            now = x[i];
            nowct = 1;
        }
    }
    vct.emplace_back(now, nowct);
    // for(auto [x, y] : vct)
    //     cout << ":" << x << ' ' << y << endl;
    int zc[n+5] = {};
    int ct = 0;
    for(auto [x, y] : vct) {
        if(x == 0) {
            zc[++ct] = y;
        }
    }
    int sum = 0;
    rep(i,1,ct) {
        if(zc[i] % 2 == 1) {
            cout << 0 << endl;
            return;
        }
        sum += zc[i] / 2;
    }
    ll jc[n+5] = {1}, jc2[n+5] = {0, 1, 1};
    rep(i,1,n) jc[i] = jc[i-1] * i % mod;
    rep(i,3,n) jc2[i] = jc2[i-2] * i % mod;

    ll ans = jc[sum];
    rep(i,1,ct) {
        ans *= frac(1, jc[zc[i] / 2]);
        ans %= mod;
    }
    rep(i,1,ct) {
        ans *= jc2[zc[i] - 1];
        ans %= mod;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin>>t;
    solve();

    return 0;
}
