#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int p,k; cin >> p >> k;
    string str;
    for(int i=1;i<=p;i++) {
        string tmp; cin >> tmp;
        str+=tmp;
    }
    int n = str.size();
    str = ' ' + str;
    int isword[n+5][n+5] = {}, ct[n+5][n+5] = {};
    int s; cin >> s;
    string wd[s+5];
    rep(i,1,s) cin >> wd[i];
    rep(l,1,n) {
        rep(r,l,n) {
            rep(i,1,s) {
                if(r-l+1 == wd[i].size() && str.substr(l,r-l+1) == wd[i]) {
                    isword[l][r] = true;
                }
            }
        }
    }
    rep(l,1,n) rep(r,l,n) {
        rep(x,l,r) {
            rep(y,x,r) {
                if(isword[x][y]) {
                    ct[l][r] ++;
                    break;
                }
            }
        }
    }
    int dp[n+5][k+5] = {};
    rep(i,0,n) rep(j,0,k) dp[i][j] = -0x3f3f3f3f;
    dp[0][0] = 0;
    rep(i,1,n) {
        rep(j,1,k) {
            rep(x,0,i-1) {
                dp[i][j] = max(dp[i][j], dp[x][j-1] + ct[x+1][i]);
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }
    cout << dp[n][k] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
