#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
typedef long long ll;
using namespace std;
constexpr ll mod = 998244353;
constexpr int maxn = 5e3+10;
int a[maxn], f[2][maxn][4];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;
    char ch[n+5];
    rep(i,1,n) cin>>ch[i];
    rep(i,1,n) a[i] = (ch[i] == '1');
    f[0][0][0] = 1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            for(int k=0;k<=3;k++)
                f[i%2][j][k] = 0;
        }
        for(int j=0;j<=m;j++) {
            for(int k=0;k<=3;k++) {
                if(!(a[i] == 0 && k == 3)) {                // 不操作
                    f[i%2][j][a[i] | ((k&1)<<1)] += f[!(i%2)][j][k];
                    f[i%2][j][a[i] | ((k&1)<<1)] %= mod;
                }
                if(j > 0 && !(a[i] == 1 && k == 3)) {       // 操作
                    f[i%2][j][(!a[i]) | ((k&1)<<1)] += f[!(i%2)][j-1][k];
                    f[i%2][j][(!a[i]) | ((k&1)<<1)] %= mod;
                }
            }
        }
    }
    int ans = 0;
    for(int j=0;j<=m;j++) {
        for(int k=0;k<=3;k++){
            ans = (ans + f[n%2][j][k]) % mod;
        }
    }
    cout << ans << endl;
}