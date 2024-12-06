#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    int a[n+5] = {};
    for(int i=1;i<=n;i++) cin >> a[i];
    int ct[n+5][105] = {};
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=100;j++) {
            ct[i][j] = ct[i-1][j] + (a[i] == j);
        }
    }
    while(m--) {
        int x,y; cin >> x >> y;
        int cur[105] = {};
        for(int i=1;i<=100;i++)
            cur[i] = ct[y][i] - ct[x-1][i];
        int ans = 0x3f3f3f3f;
        for(int i=1;i<=100;i++) {
            int tmp = 0;
            for(int j=1;j<=100;j++) {
                tmp += abs(i - j) * cur[j];
            }
            ans = min(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}