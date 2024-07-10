#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5]; rep(i,1,n) cin >> a[i];
    // f[n][m]: for i in 1..n, select a set of size m, minimum cost of actions, s.t. f[i][j] <= i - j
    // max(y) s.t. f[n][y] <= inf
    map<int,int> mp;
    rep(i,1,n) mp[a[i]]++;
    vector<int> v;
    for(const auto &[x,y] : mp)
        v.push_back(y);
    int dp[n+5][n+5];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i=1;i<=v.size();i++) {
        for(int j=0;j<=i;j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if(j != 0) { 
                if(dp[i-1][j-1] + v[i-1] <= i - j) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + v[i-1]);
                }
            }
        }
    }
    int ans = -1;
    rep(i,0,v.size()) {
        if(dp[v.size()][i] < 0x3f3f3f3f)
            ans = max(ans, i);
    }
    cout << v.size() - ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}