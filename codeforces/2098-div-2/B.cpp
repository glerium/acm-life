#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,k; cin >> n >> k;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    sort(a.begin() + 1, a.begin() + n + 1);
    int ans = 0;
    if(n & 1) {
        if(k == 0) {
            cout << 1 << endl;
            return;
        }
        ans = 1;
        a.erase(a.begin() + (n + 1) / 2);
        n--;
        k--;
    }
    if(k & 1) k--;
    int l = (n-k)/2,
        r = n-(n-k)/2+1;
    // cout << l << ' ' << r << endl;
    ans = max(ans, a[r] - a[l] + 1);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
