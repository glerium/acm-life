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
    vector<int> son[n+5];
    rep(i,2,n) {
        int x; cin >> x;
        son[x].push_back(i);
    }
    function<ll(int)> dfs = [&](int x) -> ll {
        ll sum = 0;
        ll ret = 0;
        for(auto i : son[x]) {
            sum += a[i];
            ret += dfs(i);
        }
        return ret + (son[x].empty() ? 0ll : max(0ll, a[x] - sum));
    };
    ll ans = dfs(1);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
