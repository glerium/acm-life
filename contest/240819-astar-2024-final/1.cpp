#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[30],b[30][30],c[30][30][30];
ll best[30];
ll v[10][3];
bitset<30> vis;
void dfs(int x, ll now) {
    if(x % 3 == 0 && x != 0) {
        auto tt = v[x/3-1];
        now += c[tt[0]][tt[1]][tt[2]];
    }
    best[x] = max(best[x], now);
    if(x == n) return;
    // if(best[x] > now) return;
    for(int i=0;i<n;i++) {
        if(vis[i]) continue;
        vis[i] = true;
        v[x/3][x%3] = i;
        dfs(x+1, now);
        vis[i] = false;
    }
}
ll f[30];
int main() {
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=0;i<=n;i++) best[i] = -1e6;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> b[i][j];
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            for(int k=j+1;k<=n;k++) {
                c[i][j][k] = -1e6;
                c[i][j][k] = max(max(a[i],a[j]),a[k]);
                c[i][j][k] = max(c[i][j][k], max(b[i][j], max(b[j][k], b[i][k])));
                c[i][j][k] = max(c[i][j][k], b[i][j] * b[i][k] * b[j][k]);
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<=n;j++) {
            for(int k=j+1;k<=n;k++) {
                c[i][j][k] = c[i+1][j+1][k+1];
            }
        }
    }
    dfs(0, 0);
    cout << best[n] << endl;
    return 0;
}