#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,m,k; cin >> n >> m >> k;
    auto check = [&](int x) -> bool {
        ll ms = m / (x + 1) * x + m % (x + 1);
        return 1ll * n * ms >= k;
    };
    int l=1, r=m, mid, ans;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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
