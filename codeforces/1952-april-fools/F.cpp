#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 21;
    int a[22][22];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            char ch; cin >> ch;
            a[i][j] = ch - '0';
        }
    }
    int ans = 0;
    for(int i=1;i+3<=n;i++) {
        for(int j=1;j+3<=n;j++) {
            int s = 0;
            for(int x=i;x<=i+3;x++) {
                for(int y=j;y<=j+3;y++)
                    s += a[x][y];
            }
            ans = max(ans, s);
        }
    }
    cout << ans << endl;
}