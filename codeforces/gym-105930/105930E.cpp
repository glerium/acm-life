#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
void solve() {
    ll n,k; cin >> n >> k;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    sort(a.begin() + 1, a.begin() + 1 + n);
    ll s = k;
    rep(i,1,n) s += a[i];
    vector<ll> factors;
    int lim = sqrt(s);
    rep(i,1,lim) {
        if(s % i == 0) {
            factors.push_back(i);
            if(1ll * i * i != s) {
                factors.push_back(s / i);
            }
        }
    }
    ll mx = *max_element(a.begin() + 1, a.begin() + 1 + n);
    vector<ll> sm(n + 5);
    rep(i,1,n) sm[i] = sm[i-1] + a[i];
    ll ans = 1;
    for(ll x : factors) {
        if(x >= mx) {
            if(n * x <= s && s % x == 0) {
                ans = max(ans, x);
            }
        } else {
            ll used = 0;
            int bef = 0;
            for(ll i = 0; i * x + 1 <= mx; i++) {
                ll l = i * x + 1, r = (i + 1) * x;
                ll target = (i + 1) * x;
                int it = upper_bound(a.begin() + 1, a.begin() + 1 + n, r) - a.begin();
                int ct = it - bef - 1;
                ll cur_sum = sm[it - 1] - sm[bef];
                used += target * ct - cur_sum;
                bef = it - 1;
            }
            if(used <= k && (k - used) % x == 0) {
                ans = max(ans, x);
            }
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
