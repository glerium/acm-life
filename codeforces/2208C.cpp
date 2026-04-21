#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    vector<int> c(n+5), p(n+5);
    rep(i,1,n) cin >> c[i] >> p[i];
    vector<double> f(n+5);
    for(int i=n;i>=1;i--) {
        f[i] = max(f[i+1], (1 - p[i] * 0.01) * f[i+1] + c[i]);
    }
    cout << fixed << setprecision(10) << f[1] << endl;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}