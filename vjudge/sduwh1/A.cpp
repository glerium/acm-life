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
    bool ok[n+5] = {};
    rep(i,1,n) {
        if(s[i] == '1') {
            ok[i] = ok[i+1] = ok[i+2] = true;
        }
    }
    int ans = 0;
    rep(i,1,n) ans += ok[i];
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
