#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
ll qpow(ll x, ll y) {
    if(!y) return 1;
    if(y&1) return x * qpow(x, y-1);
    return qpow(x*x, y/2);
}
bool check(ll x) {
    if(x < 10) return false;
    int a[20] = {};
    int ct = 0;
    while(x) {
        a[++ct] = x % 10;
        x /= 10;
    }
    rep(i,1,ct-1) {
        if(a[ct] <= a[i])
            return false;
    }
    return true;
}
ll ct(ll x) {
    if(x < 10) return 0;
    int a[30] = {}, n = 0;
    {
        ll x_ = x;
        while(x_) {
            a[++n] = x_ % 10;
            x_ /= 10;
        }
    }
    for(int l=1,r=n;l<r;l++,r--) {
        swap(a[l], a[r]);
    }
    // < n
    ll ret = 0;
    rep(i,2,n-1) {
        rep(j,1,9) {
            ret += qpow(j, i-1);
        }
    }
    // == n
    for(int i=1;i<=n;i++) {     // stuck at i-1, loop through a[i]
        if(i != 2 && a[i-1] >= a[1]) {
            break;
        }
        rep(j,i==1?1:0,min(a[i]-1,a[1]-1)) {
            ret += qpow((i!=1) ? a[1] : j, n-i);
        }
    }
    if(check(x)) ret++;
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll l, r; cin >> l >> r;
    // cout << ct(l-1) << ' ' << ct(r) << endl;
    cout << ct(r) - ct(l-1) << endl;
    return 0;
}
