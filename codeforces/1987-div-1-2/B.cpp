#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    ll a[n+5]; rep(i,1,n) cin >> a[i];
    ll last = a[1];
    multiset<ll> d;
    rep(i,1,n) {
        if(last > a[i])
            d.insert(last - a[i]);
        else
            last = a[i];
    }
    ll ct = d.size();
    ll ans = 0;
    ll lastt = 0;
    for(auto i : d) {
        if(lastt == i) continue;
        ans += (ct + 1) * (i - lastt);
        lastt = i;
        ct -= d.count(i);
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
