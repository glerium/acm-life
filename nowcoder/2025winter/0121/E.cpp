#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5] = {};
    ll ans = 0;
    rep(i,1,n) cin >> a[i];
    sort(a+1, a+1+n);
    int tgt1 = (1 + n/2)/2;
    int tgt2 = (n/2+1 + n) / 2;
    if(a[tgt1] != a[tgt2]) {
        rep(i,1,n/2) {
            ans += abs(a[i] - a[tgt1]);
        }
        rep(i,n/2+1,n) {
            ans += abs(a[i] - a[tgt2]);
        }
    }else{
        ll cur1 = 0, cur2 = 0;
        rep(i,1,n/2) {
            cur1 += abs(a[i] - (a[tgt1]-1));
        }
        rep(i,n/2+1,n) {
            cur1 += abs(a[i] - a[tgt2]);
        }

        rep(i,1,n/2) {
            cur2 += abs(a[i] - a[tgt1]);
        }
        rep(i,n/2+1,n) {
            cur2 += abs(a[i] - (a[tgt2]+1));
        }
        ans = min(cur1, cur2);
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
