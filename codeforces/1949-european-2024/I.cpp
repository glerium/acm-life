#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int n;
struct Circle {
    int x, y;
    int r;
}a[1007];
signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i].x >> a[i].y >> a[i].r;
    bool found = false;
    for(int i=1;i<=n;i++) {
        int tan_cnt = 0;
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            ull dis2 = 1ull * (a[i].x - a[j].x) * (a[i].x - a[j].x) + 1ull * (a[i].y - a[j].y) * (a[i].y - a[j].y);
            ull sumr2 = 1ull * (a[i].r + a[j].r) * (a[i].r + a[j].r);
            ull sumr3 = 1ull * (a[i].r - a[j].r) * (a[i].r - a[j].r);
            if(dis2 == sumr2 || dis2 == sumr3) {
                tan_cnt++;
                continue;
            }
        }
        cout << tan_cnt << endl;
        if(tan_cnt <= 1)
            found = true;
    }
    puts(found ? "YES" : "NO");
}