#include <bits/stdc++.h>
#define int long long
#define yes s += '1'
#define no s += '0'
using namespace std;
constexpr int maxn = 2e5+10;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k; cin >> n >> m >> k;
    int a[n+5][m+5], ct[m+5]={}, ect[n+5]={}; 
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
    for(int i=1;i<=k;i++) {
        int x, y; cin >> x >> y;
        ct[y]++;
        ect[x]++;
    }
    int ans[n+5] = {};
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i][j])
                ans[i] += ct[j];
        }
        ans[i] -= ect[i];
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}