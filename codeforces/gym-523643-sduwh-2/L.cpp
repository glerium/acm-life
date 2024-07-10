#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int to, nxt;
};
void solve(){
    int n,m; cin >> n >> m;
    vector<bitset<105>> f(n+2);
    for(int i=1;i<=m;i++) {
        int x,y; cin >> x >> y;
        f[x][y] = 1;
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++){
            if(f[i][k]) {
                f[i] |= f[k];
            }
        }
    }
    int pre[n+5]={}, suf[n+5]={};
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(f[i][j]) {    
                pre[i]++;
                suf[j]++;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        if(f[i][i]) {
            cout << string(n, '0') << endl;
            return;
        }
    }
    for(int i=1;i<=n;i++) {
        if(pre[i] <= n/2 && suf[i] <= n/2) {
            cout << '1';
        }else {
            cout << '0';
        }
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}