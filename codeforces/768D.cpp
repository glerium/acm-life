#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e3+10;
constexpr int maxm = 1e4+10;
constexpr ll mod = 998244353;
int k,q,ans[maxn];
double p[maxn],f[maxm][maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>k>>q;
    for(int i=1;i<=q;i++) cin>>p[i];
    memset(ans, 0x3f, sizeof(ans));
    f[0][0]=1;
    for(int i=1;i<=10000;i++) {
        for(int j=1;j<=k;j++) {
            f[i][j] = f[i-1][j] * j / k + f[i-1][j-1] * (k-j+1) / k;
        }
    }
    for(int i=1;i<=q;i++) {
        p[i] /= 2000;
        for(int j=1;j<=10000;j++) {
            if(f[j][k] >= p[i]) {
                cout << j << endl;
                break;
            }
        }
    }
    return 0;
}
