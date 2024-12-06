#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5][n+5] = {};
    int ct = 0;
    rep(i,1,n) {
        rep(j,i,n) {
            a[i][j] = ++ct;
        }
    }
    rep(i,1,n) {
        rep(j,1,n) {
            if(!a[i][j])
                a[i][j] = a[j][i];
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
