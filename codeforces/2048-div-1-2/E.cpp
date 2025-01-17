#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,m; cin >> n >> m;
    // n=1
    //  m==1: yes
    //  m>=2: no
    // n=2
    //  m<=2: yes
    //  m>=3: no
    if(n == 1) {
        cout << "YES" << endl;
        rep(i,1,m) cout << 1 << ' ';
        cout << endl;
        return;
    }
    if(n < m) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    // int a[n+5][m+5] = {};
    rep(i,1,n*2) {
        rep(j,1,m) {
            cout << j << ' ';
        }
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
