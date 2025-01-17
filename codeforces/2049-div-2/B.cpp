#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    rep(i,1,n) {
        rep(j,i+1,n) {
            if(s[i] == 'p' && s[j] == 's') {
                cout << "NO" << endl;
                return;
            }
        }
    }
    // int ls = 1, fp = n;
    rep(i,1,n) {
        rep(j,i+1,n) {
            if(s[i] != 's' || s[j] != 'p')
                continue;
            // cout << n-i+1 << ' ' << j << endl;
            if(n-i+1 + j - n < min(n-i+1,j)) {
                cout << "NO" << endl;
                return;
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
