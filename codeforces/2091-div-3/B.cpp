#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,x; cin >> n >> x;
    int a[n+5] = {};
    rep(i,1,n) cin >> a[i];
    int ans = 0;
    vector<int> vec;
    rep(i,1,n) {
        if(a[i] >= x) {
            ans++;
        } else {
            vec.push_back(a[i]);
        }
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int ct = 0, mi = 1e9;
    for(auto i : vec) {
        mi = min(mi, i);
        ct++;
        if(1ll * ct * mi >= x) {
            ans++;
            ct = 0;
            mi = 1e9;
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
