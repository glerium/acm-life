#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5] = {}, b[n+5] = {};
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    int ct = 0, mx = 0;
    rep(i,1,n) {
        if(b[i] > a[i]) {
            ct++;
            mx = b[i] - a[i];
        }
    }
    if(ct >= 2) {
        cout << "NO" << endl;
        return;
    }else{
        rep(i,1,n) {
            if(b[i] <= a[i]) {
                a[i] -= mx;
                if(a[i] < b[i]) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
