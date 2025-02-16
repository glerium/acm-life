#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,l,r; cin >> n >> l >> r;
    int a[n+6] = {};
    rep(i,1,n) cin >> a[i];
    multiset<int> m1, m2, stl, str; 
    rep(i,l,r) m1.insert(a[i]);
    m2 = m1;
    rep(i,1,l-1) stl.insert(a[i]);
    rep(i,r+1,n) str.insert(a[i]);
    ll ans = accumulate(a + l, a + r + 1, 0ll);
    ll now = ans;
    while(!m1.empty() && !stl.empty()) {
        if(*prev(m1.end()) <= *stl.begin())
            break;
        now += *stl.begin() - *prev(m1.end());
        stl.erase(stl.begin());
        m1.erase(prev(m1.end()));
    }
    ans = min(ans, now);

    now = accumulate(a + l, a + r + 1, 0ll);
    while(!m2.empty() && !str.empty()) {
        if(*prev(m2.end()) <= *str.begin())
            break;
        now += *str.begin() - *prev(m2.end());
        str.erase(str.begin());
        m2.erase(prev(m2.end()));
    }
    ans = min(ans, now);

    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
