#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr ll mod = 1e9+7;
constexpr int maxn = 305;
int n,q;
int f[maxn][3][maxn][maxn],f2[maxn][maxn][maxn],w[maxn][maxn][maxn];
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    cin >> s; s = ' ' + s;
    if(s[1] == '?') {
        f[1][0][1][0] = 1;
        f[1][1][0][1] = 1;
        f[1][2][0][0] = 1;
    }else{
        if(s[1] == 'a')
            f[1][0][1][0] = 1;
        else if(s[1] == 'b')
            f[1][1][0][1] = 1;
        else
            f[1][2][0][0] = 1;
    }
    for(int i=2;i<=n;i++) {
        for(int j=0;j<i;j++) {
            for(int k=0;k<i;k++) {
                // if(j+k+1>i) continue;
                if((s[i] == 'a' || s[i] == '?')) {
                    f[i][0][j+1][k] += (f[i-1][1][j][k] + f[i-1][2][j][k]) % mod;
                    f[i][0][j+1][k] %= mod;
                }
                if((s[i] == 'b' || s[i] == '?')) {
                    f[i][1][j][k+1] += (f[i-1][0][j][k] + f[i-1][2][j][k]) % mod;
                    f[i][1][j][k+1] %= mod;
                }
                if((s[i] == 'c' || s[i] == '?')) {
                    f[i][2][j][k] += (f[i-1][0][j][k] + f[i-1][1][j][k]) % mod;
                    f[i][2][j][k] %= mod;
                }
            }
        }
    }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            if(n-i-j<0) continue;
            for(int l=0;l<=2;l++) {
                f2[i][j][n-i-j] += f[n][l][i][j];
                f2[i][j][n-i-j] %= mod;
            }
        }
    }
    for(int i=1;i<=n+1;i++) {
        for(int j=1;j<=n+1;j++) {
            for(int k=1;k<=n+1;k++) {
                w[i][j][k] = (((ll)w[i-1][j][k] + (ll)w[i][j-1][k] + (ll)w[i][j][k-1] - (ll)w[i-1][j-1][k] - (ll)w[i-1][j][k-1] 
                            - (ll)w[i][j-1][k-1] + (ll)w[i-1][j-1][k-1] + (ll)f2[i-1][j-1][k-1]) % mod + mod) % mod;
            }
        }
    }
    int a=0,b=0,c=0;
    for(int i=1;i<=n;i++) {
        if(s[i] == 'a') a++;
        else if(s[i] == 'b') b++;
        else if(s[i] == 'c') c++;
    }
    for(int i=1;i<=q;i++) {
        int x, y, z; cin >> x >> y >> z;
        cout << w[min(n+1,x+1+a)][min(n+1,y+1+b)][min(n+1,z+1+c)] << endl;
    }
    return 0;
}