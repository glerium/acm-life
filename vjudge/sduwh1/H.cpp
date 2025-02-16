#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    ll a,b; cin >> a >> b;
    ll ans = 0;
    for(int i=60;i>=0;i--) {
        if((a&(1ll<<i)) != (b&(1ll<<i))) {
            if(!(ans >= a && ans <= b)) {
                for(int j=0;j<=i;j++) {
                    if(ans + (1ll << j) >= a) {
                        ans += 1ll << j;
                        break;
                    }
                }
            }
            break;
        }
        ans += a & (1ll << i);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
