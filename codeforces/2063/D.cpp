#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n, m; cin >> n >> m;
    int a[n+5] = {}, b[m+5] = {};
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) cin >> b[i];
    sort(a+1, a+1+n);
    sort(b+1, b+1+m);
    ll ans = 0;
    int al = 1, ar = n, bl = 1, br = m, adel = 0, bdel = 0;
    int kmax;
    if(n*2 < m) kmax = n;
    else if(m*2 < n) kmax = m;
    else kmax = (n + m) / 3;
    vector<ll> ansv;
    rep(k,1,kmax) {
        int arem = ar - al + 1 - adel,
            brem = br - bl + 1 - bdel;
        if(arem == 0) {
            // cancel a for one step
            al--, ar++;
            bdel--;
            ans -= a[ar] - a[al];
            // progress on b
            ans += b[br] - b[bl];
            bl++, br--;
            adel++;
        }else if(brem == 0) {
            // cancel b for one step
            bl--, br++;
            adel--;
            ans -= b[br] - b[bl];
            // progress on a
            ans += a[ar] - a[al];
            al++, ar--;
            bdel++;
        }
        bool asel;
        if(brem < 2) asel = true;
        else if(arem < 2) asel = false;
        else asel = (a[ar] - a[al]) > (b[br] - b[bl]);
        if(asel) {
            // progress on a
            ans += a[ar] - a[al];
            al++, ar--;
            bdel++;
        }else{
            // progress on b
            ans += b[br] - b[bl];
            bl++, br--;
            adel++;
        }
        ansv.push_back(ans);
    }
    cout << kmax << endl;
    for(auto i : ansv) cout << i << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
