#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
void solve() {
    int n; cin >> n;
    int a[n+5] = {}, b[n+5] = {};
    rep(i,2,n-1) cin >> b[i];
    int now = 0;
    for(int i=2;i<=n-1;i++) {
        if(b[i] == 1) {
            if(a[i-1] == 0) {
                now++;
                a[i-1] = a[i] = a[i+1] = now;
            }else{
                a[i] = a[i+1] = a[i-1];
            }
        }
    }
    rep(i,1,n) {
        if(a[i] == 0) {
            now++;
            a[i] = now;
        }
    }
    // rep(i,1,n) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    rep(i,2,n-1) {
        int bb;
        if(a[i] == a[i-1] && a[i] == a[i+1]) bb = 1;
        else bb = 0;
        if(bb != b[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}