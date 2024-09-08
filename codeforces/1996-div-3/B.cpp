#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,k; cin>>n>>k;
    string s[n+5];
    rep(i,0,n-1) cin >> s[i];
    int ct = n / k;
    string ans[ct+5];
    rep(i,0,ct-1) {
        ans[i] = string(ct, '*');
        rep(j,0,ct-1) {
            ans[i][j] = s[i*k][j*k];
        }
    }
    rep(i,0,ct-1) cout << ans[i] << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
