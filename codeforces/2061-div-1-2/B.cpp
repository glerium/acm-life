#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5] = {};
    rep(i,1,n) cin >> a[i];
    sort(a+1,a+1+n);
    int mx = 0;
    rep(i,1,n-1) {
        if(a[i] == a[i+1])
            mx = i;
    }
    int fnd = a[mx];
    rep(i,mx,n)
        a[i] = a[i+2];
    n -= 2;
    int mn = 0x3f3f3f3f;
    rep(i,1,n-1) {
        if(a[i+1] - a[i] < 2 * fnd) {
            cout << a[i] << ' ' << a[i+1] << ' ' << fnd << ' ' << fnd << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
