#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin>>n;
    int a[n+5]; rep(i,1,n) cin>>a[i];
    auto allsame = [&]() {
        rep(i,2,n) if(a[i] != a[1]) return false;
        return true;
    };
    if(allsame()) {
        cout << -1 << endl;
        return;
    }
    int last = -1, from = 0, ans = 0x3f3f3f3f;
    rep(i,1,n) {
        if(a[i] != last) {
            if(last == a[1])
                ans = min(ans, i - from);
            from = i;
            last = a[i];
        }
    }
    if(last == a[1])
        ans = min(ans, n - from + 1);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
