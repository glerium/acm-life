#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int inf = 114514;
int main() {
    int n,m; cin >> n >> m;
    int x1 = inf, x2 = 0, y1 = inf, y2 = 0;
    rep(i,1,n) rep(j,1,m) {
        char ch; cin >> ch;
        if(ch == '.') continue;
        x1 = min(x1, i);
        x2 = max(x2, i);
        y1 = min(y1, j);
        y2 = max(y2, j);
    }
    int xl = x2 - x1 + 1, yl = y2 - y1 + 1;
    int g = gcd(xl, yl);
    xl /= g; yl /= g;
    rep(i,1,xl) {
        rep(j,1,yl)
            cout << 'x';
        cout << endl;
    }
}