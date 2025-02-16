#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    struct Work {
        ll d, v;
        bool operator<(const Work& rhs) const {
            return d < rhs.d;
        }
    } a[n+5] = {};
    rep(i,1,n) {
        cin >> a[i].d >> a[i].v;
    }
    set<int> ds;
    map<int, multiset<int>> mp;
    rep(i,1,n) mp[a[i].d].insert(a[i].v);
    rep(i,1,n) ds.insert(a[i].d);
    ds.insert(0);
    sort(a+1, a+n+1);
    ll last = a[n].d;
    ll ans = 0;
    priority_queue<ll> q;
    for(auto i : mp[*prev(ds.end())]) q.push(i);
    for(auto i = next(ds.rbegin()); i != ds.rend(); i++) {
        int ct = min(ll(q.size()), last - *i);
        rep(j,1,ct) {
            int tmp = q.top(); q.pop();
            ans += tmp;
        }
        for(auto j : mp[*i])
            q.push(j);
        last = *i;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
