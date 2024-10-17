#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5+10;
int n,m,k,sz[maxn];
// set<int,greater<int>> st;
string s;
int a[maxn];
int count_z(int l, int r) {
    return sz[r] - sz[l-1];
}
bool check(int x) {
    int dp[n+5][6][2];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=k;j++) {
            if(s[i] == '0') {
                dp[i][j][0] = min({dp[i][j][0], dp[i-1][j][0], dp[i-1][j][1]});
                dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][1] + 1);
            }else if(s[i] == '1') {
                dp[i][j][0] = min({dp[i][j][0], dp[i-1][j][0]});
                dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][1]);
            }
            if(i >= x && j >= 1) {
                dp[i][j][1] = min(dp[i][j][1], dp[i-x][j-1][0] + count_z(i-x+1, i));
            }
        }
    }
    return min(dp[n][k][0], dp[n][k][1]) <= m;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k >> s;
    s = ' ' + s;
    for(int i=1;i<=n;i++) {
        sz[i] = sz[i-1] + (s[i] == '0');
    }
    int l=0,r=n,mid,ans=-1;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    if(ans == 0) ans = -1;
    cout << ans << endl;
}