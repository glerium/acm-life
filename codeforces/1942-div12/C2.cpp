#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, x, y; cin >> n >> x >> y;
    int a[x+5];
    for(int i=1;i<=x;i++) cin >> a[i];
    sort(a+1, a+1+x);
    int ans = 0;
    int sel = 0;
    a[x+1] = a[1] + n;
    for(int i=1;i<=x&&sel<y;i++) {
        int maxsel = max(0, (a[i+1] - a[i]) / 2 - 1);
        int nowsel = min(maxsel, y - sel);
        ans += nowsel;
        if(maxsel == y - sel && (a[i+1] - a[i]) % 2 == 0)
            ans++;
        sel += nowsel;
    }
    for(int i=1;i<x;i++) {
        if(a[i+1] - a[i] == 2)
            ans++;
    }
    if(a[1] == 1 && a[x] == n-1 || a[1] == 2 && a[x] == n)
        ans++;
    x += sel;
    ans += max(0, x - 2);
    cout << ans << endl;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}