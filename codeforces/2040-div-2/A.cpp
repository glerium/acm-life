#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,k; cin >> n >> k;
    int a[n+5] = {};
    rep(i,1,n) cin >> a[i];
    for(int i=1;i<=n;i++) {
        bool ok = true;
        for(int j=1;j<=n;j++) {
            if(i == j) continue;
            if((a[i] - a[j]) % k == 0) {
                ok = false;
                break;
            }
        }
        if(ok) {cout << "YES" << endl << i << endl; return;}
    }
    cout << "NO" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
