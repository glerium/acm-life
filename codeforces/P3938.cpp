#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[70];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    f[0] = 1;
    f[1] = 1;
    for(int i=2;i<=65;i++)
        f[i] = f[i-1] + f[i-2];
    int m; cin >> m;
    for(int i=1;i<=m;i++) {
        ll x, y; cin >> x >> y;
        int jx=65, jy=65;
        while(y != x) {
            if(x > y) {
                while(f[jx] >= x) jx--;
                x -= f[jx];
            }else {
                while(f[jy] >= y) jy--;
                y -= f[jy];
            }
        }
        cout << x << '\n';
    }
    return 0;
}
