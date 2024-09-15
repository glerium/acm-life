#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    string s,t; cin>>s>>t;
    int n=s.size(), m=t.size();
    s = ' ' + s;
    t = ' ' + t;
    ll f[n+2][m+2][m+2] = {};
    for(int i=1;i<=m;i++) {
        if(s[1] == t[i])
            f[1][i][i] = 1;
    }
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            for(int k=j;k<=m;k++) {
                if(j == k && t[j] == s[i])
                    f[i][j][k] = 1;
                f[i][j][k] += f[i-1][j][k] * 2 % mod;
                f[i][j][k] %= mod;
                for(int l=j;l<=k;l++) {
                    f[i][j][k] += f[i-1][j][l] * f[i-1][l+1][k] % mod;
                    f[i][j][k] %= mod;
                }
                for(int l=j;l<=k;l++) {
                    if(t[l] != s[i]) continue;
                    if(l == j)
                        f[i][j][k] += f[i-1][l+1][k];
                    else if(l == k)
                        f[i][j][k] += f[i-1][j][l-1];
                    else
                        f[i][j][k] += f[i-1][j][l-1] * f[i-1][l+1][k] % mod;
                    f[i][j][k] %= mod;
                }
            }
        }
    }
    cout << f[n][1][m] << endl;
    return 0;
}
