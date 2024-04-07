#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, x, y; cin >> n >> x >> y;
    int a[x+5];
    for(int i=1;i<=x;i++) cin >> a[i];
    sort(a+1, a+1+x);
    int ans = 0;
    for(int i=1;i<x;i++) {
        if(a[i+1] - a[i] == 2)
            ans++;
    }
    if(a[1] == 1 && a[x] == n-1 || a[1] == 2 && a[x] == n)
        ans++;
    ans += max(0, x - 2);
    cout << ans << endl;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}