#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 5e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5] = {};
    rep(i,1,n) cin >> a[i];
    auto check = [&](int x) -> bool {
        // 1...x   n-x+1...n
        for(int i=1;i<=x;i++) {
            if(a[i] * 2 > a[n - x + i]) {
                return false;
            }
        }
        return true;
    };
    int l = 0, r = n/2, mid, ans;
    while(l <= r) {
        mid = l + r >> 1;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }else
            r = mid - 1;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
