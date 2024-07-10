#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,k,pb,ps; cin >> n >> k >> pb >> ps;
    int p[n+5] = {};
    ll a[n+5] = {};
    rep(i,1,n) cin >> p[i];
    rep(i,1,n) cin >> a[i];
    auto getans = [&](int s) -> ll {
        ll fix = a[s];
        ll ans = 0;
        for(int i=1;i<=min(k,n+5);i++) {
            ans = max(ans, fix + (k-i)*a[s]);
            s = p[s];
            fix += a[s];
        }
        return ans;
    };
    ll sb = getans(pb), ss = getans(ps);
    // cout << sb << ' ' << ss << endl;
    if(sb > ss) cout << "Bodya" << endl;
    else if(sb < ss) cout << "Sasha" << endl;
    else cout << "Draw" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
