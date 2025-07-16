#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define rep(i, o, p) for(int i = o; i <= p; i++)
void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    int g = 0;
    rep(i,1,n) g = gcd(g, a[i]);
    rep(i,1,n) a[i] /= g;
    if(count(a.begin() + 1, a.begin() + 1 + n, 1) != 0) {
        cout << n - 1 << endl;
        return;
    }
    rep(i,1,n) rep(j,1,n) {
        if(i == j) continue;
        if(a[i] % a[j] == 1) {
            cout << n << endl;
            return;
        }
    }
    cout << n + 1 << endl;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}