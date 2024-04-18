#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e3+10;
constexpr int maxm = 1e4+10;
constexpr ll mod = 998244353;
int w,b;
double f[maxn][maxn];       // white: i, black: j
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> w >> b;
    for(int i=1;i<=1000;i++) f[0][i] = 0;
    for(int i=1;i<=1000;i++) f[i][0] = 1;
    for(int i=1;i<=w;i++) {
        for(int j=1;j<=b;j++) {
            f[i][j] += 1.0 * i / (i+j);
            if(j >= 2) f[i][j] += 1.0 * j / (i+j) * (j-1) / (i+j-1) * i / (i+j-2) * f[i-1][j-2];
            if(j >= 3) f[i][j] += 1.0 * j / (i+j) * (j-1) / (i+j-1) * (j-2) / (i+j-2) * f[i][j-3];
        }
    }
    cout << fixed << setprecision(12) << f[w][b] << endl;
    return 0;
}
