#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    ll a[n+5] = {};
    for(int i=1;i<=n;i++) cin >> a[i];
    bool same = true;
    for(int i=1;i<=n-1;i++) {
        if(a[i] != a[i-1])
            same = false;
    }
    if(same) {
        cout << 0 << endl;
        return 0;
    }
    sort(a+1,a+1+n);
    n = unique(a+1, a+1+n) - a - 1;
    // for(int i=1;i<=n;i++)
    //     cout << a[i] << ' ';
    // cout << endl;
    if(a[1] != 0) {
        cout << "-1" << endl;
        return 0;
    }
    ll ans = 1;
    for(int i=1;i<=n-1;i++) {
        ans += a[i+1] - a[i] - 1;
    }
    cout << ans << endl;
    return 0;
}
