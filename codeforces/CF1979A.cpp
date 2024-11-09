#include <bits/stdc++.h>
#define int long long
#define yes s += '1'
#define no s += '0'
using namespace std;
constexpr int maxn = 2e5+10;
int n,x,y,a[maxn];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int ans = 0x3f3f3f3f;
        int last = -1;
        for(int i=1;i<=n;i++) {
            int x; cin >> x;
            if(i != 1) ans = min(ans, max(x, last));
            last = x;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}