#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    sort(a.begin() + 1, a.begin() + 1 + n, greater<>());
    rep(i,1,n-1) {
        if(a[i] == a[i+1]) {
            cout << "-1" << endl;
            return;
        }
    }
    // cout << "YES" << endl;
    rep(i,1,n) cout << a[i] << ' ';
    cout << endl;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}