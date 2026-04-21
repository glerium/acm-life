#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
void solve() {
    int n,m; cin >> n >> m;
    int target = n + 2 * m;
    int limx = 0;
    while(2 * (limx + 1) * (limx + 1) <= target)
        limx++;
    // cerr << limx << endl;
    rep(x,1,limx) {
        if((target - x) % (2 * x + 1) != 0)
            continue;
        int y = (target - x) / (2 * x + 1);
        if(y - x > n) continue;
        cout << x << ' ' << y << endl;
        return;
    }
    cout << -1 << endl;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}