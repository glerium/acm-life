#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    int a[n+5] = {};
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> v;
    for(int i=2;i<n;i++) {
        if(a[i] < a[i-1] && a[i] < a[i+1])
            v.push_back(i);
    }
    long double ans = 0;
    auto check = [&](int x) -> void {
        long double s = a[x];
        int ct = 1;
        for(int i=x+1; i<=n && a[i-1] < a[i]; i++) {
            ct++;
            s += a[i];
        }
        for(int i=x-1; i>=0 && a[i+1] < a[i]; i--) {
            ct++;
            s += a[i];
        }
        s /= ct;
        ans = max(ans, s);
    };
    for(auto i : v)
        check(i);
    cout << fixed << setprecision(10) << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}