#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,k; cin >> n >> k;
    auto getans = [&](int x) -> int {
        int ret = 0;
        for(int i=0;i<16;i++) {
            int a = bool(i&(1<<3)),
                b = bool(i&(1<<2)),
                c = bool(i&(1<<1)),
                d = bool(i&(1<<0));
            if((((a&b)^c)|d) == x) {
                ret++;
            }
        }
        return ret;
    };
    ll ans = 1;
    for(int i=0;i<k;i++) {
        ans *= getans(bool(n&(1<<i)));
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
