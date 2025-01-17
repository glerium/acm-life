#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
ll qpow(ll x, ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return x * qpow(x, y-1) % mod;
    return qpow(x * x % mod, y / 2);
}
ll frac(ll x, ll y) {
    return x * qpow(y, mod - 2) % mod;
}
void solve() {
    int n, q; cin >> n >> q;
    int a[n+5] = {}, b[n+5] = {};
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    int sa[n+5], sb[n+5];
    memcpy(sa, a, sizeof(a));
    memcpy(sb, b, sizeof(b));
    sort(sa+1, sa+1+n);
    sort(sb+1, sb+1+n);
    // map<int, multiset<int>> mp;
    // rep(i,1,n) {
    //     mp[sb[i]].insert(sa[i]);
    // }
    ll ans = 1;
    rep(i,1,n) {
        ans *= min(sa[i], sb[i]);
        ans %= mod;
    }
    cout << ans << ' ';
    while(q--) {
        int x, y; cin >> x >> y;
        if(x == 1) {
            int ed = upper_bound(sa+1, sa+1+n, a[y]) - sa;
            ed--;
            ans *= frac(min(sa[ed]+1, sb[ed]), min(sa[ed], sb[ed]));
            sa[ed]++;
            a[y]++;
            // cout << ":" << ed << endl;
        }else{
            int ed = upper_bound(sb+1, sb+1+n, b[y]) - sb;
            ed--;
            ans *= frac(min(sb[ed]+1, sa[ed]), min(sb[ed], sa[ed]));
            sb[ed]++;
            b[y]++;
            // cout << ":" << ed << endl;
        }
        ans %= mod;
        cout << ans << ' ';
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
