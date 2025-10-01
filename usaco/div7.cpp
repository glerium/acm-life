#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
void solve() {
    int n; cin >> n;
    int idx[8] = {};
    rep(i,0,7) idx[i] = -1;
    idx[0] = -1;
    int ans = 0;
    int s = 0;
    rep(i,1,n) {
        int x; cin >> x;
        s += x;
        s %= 7;
        if(idx[s] != -1)
            ans = max(ans, i - idx[s]);
        else
            idx[s] = i;
    }
    cout << ans << endl;
}
int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}