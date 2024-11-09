#include <bits/stdc++.h>
#define yes s += '1'
#define no s += '0'
using namespace std;
constexpr int maxn = 3e3+10;
string a[maxn];
int s1[maxn][maxn], s2[maxn][maxn];
int main() {
    ios::sync_with_stdio(false);
    int n,m,k; cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i] = ' ' + a[i];
    }
    if(k == 1) {
        int ans = 0;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j] == '.') ans++;
        cout << ans << endl;
        return 0;
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            s1[i][j] = s1[i][j-1] + (a[i][j] == '*');
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            s2[i][j] = s2[i-1][j] + (a[i][j] == '*');
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j+k-1<=m;j++) {
            if(s1[i][j+k-1]-s1[i][j-1] == 0)
                ans++;
        }
    }
    for(int i=1;i+k-1<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(s2[i+k-1][j]-s2[i-1][j] == 0)
                ans++;
        }
    }
    cout << ans << endl;

}