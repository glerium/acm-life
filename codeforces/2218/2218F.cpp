#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
void solve() {
    int x,y; cin >> x >> y;
    if( (x+y) % 2 == 0) x--;
    else y--;
    if(y < x || x < 0 || y < 0) {
        cout << "NO" << endl;
    } else {
        // x <= y
        cout << "YES" << endl;
        int n = 1;
        while(x) {
            cout << 1 << ' ' << n + 1 << endl;
            cout << n + 1 << ' ' << n + 2 << endl;
            x--; y--;
            n += 2;
        }
        while(y) {
            cout << 1 << ' ' << n + 1 << endl;
            y--;
            n++;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}