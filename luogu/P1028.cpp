#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[20][1005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        f[1][i] = 1;
    for(int i=2;i<=12;i++) {
        for(int j=1;j<=n;j++) {
            for(int k=1;k<=j/2;k++) {
                f[i][j] += f[i-1][k];
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=12;i++)
        ans += f[i][n];
    cout << ans << endl;
    return 0;
}