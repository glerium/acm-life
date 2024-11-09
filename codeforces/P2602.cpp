#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[20][10][10], ten[20];
void init() {
    for(int i=0;i<=9;i++)
        f[1][i][i] = 1;
    ten[0] = 1;
    for(int i=1;i<=15;i++)
        ten[i] = ten[i-1] * 10;
    // len, maxd, digit
    for(int i=2;i<=15;i++) {                // len now
        for(int j=0;j<=9;j++) {             // now maxd
            for(int k=0;k<=9;k++) {         // last maxd
                for(int l=0;l<=9;l++) {     // digit
                    f[i][j][l] += f[i-1][k][l];
                }
            }
            f[i][j][j] += ten[i-1];
        }
    }
}
void getf(ll x, ll ans[15]) {
    int len = 0;
    int a[15] = {};
    while(x) {
        a[++len] = x % 10;
        x /= 10;
    }
    for(int i=1;i<len;i++) {
        for(int j=1;j<=9;j++) {
            for(int k=0;k<=9;k++)
                ans[k] += f[i][j][k];
        }
    }
    for(int i=1;i<a[len];i++) {
        for(int k=0;k<=9;k++)
            ans[k] += f[len][i][k];
    }
    for(int i=len-1;i>=1;i--) {
        for(int j=0;j<a[i];j++) {
            for(int k=0;k<=9;k++) {
                ans[k] += f[i][j][k];
            }
        }
        for(int j=len;j>i;j--) {
            ans[a[j]] += a[i] * ten[i-1];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    ll n,m; cin >> n >> m;
    ll ans1[15]={}, ans2[15]={};
    getf(m+1, ans1);
    getf(n, ans2);
    for(int i=0;i<=9;i++)
        cout << ans1[i] - ans2[i] << ' ';
    cout << endl;
}