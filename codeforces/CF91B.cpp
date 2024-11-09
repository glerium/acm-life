#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5+10;
int n, a[maxn], mn[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=n;i>=1;i--) {
        if(i == n) mn[i] = a[i];
        else mn[i] = min(mn[i+1], a[i]);
    }
    for(int i=1;i<=n;i++) {
        int l=i, r=n, mid, ans = -1;
        while(l <= r) {
            mid = (l + r) >> 1;
            if(mn[mid] < a[i]) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        if(ans == -1) cout << "-1 ";
        else cout << ans - i - 1 << ' ';
    }
    cout << endl;
}