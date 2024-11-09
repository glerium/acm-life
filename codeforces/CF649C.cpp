#include <bits/stdc++.h>
#define int long long
#define yes s += '1'
#define no s += '0'
using namespace std;
constexpr int maxn = 2e5+10;
int n,x,y,a[maxn];
signed main() {
    ios::sync_with_stdio(false);
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    int ans = 0;
    for(int i=1;i<=n;i++) {
        if(x*2+y < a[i])
            break;
        if(a[i] & 1) {
            if(y > 0 && a[i]/2 <= x) {
                y--;
                x -= a[i]/2;
                ans++;
            } else if(y > 0 && a[i]/2 > x) {
                y -= (a[i] - x * 2);
                x = 0;
                ans++;
            } else {
                x -= a[i] / 2 + 1;
                ans++;
            }
        } else {
            if(a[i]/2 <= x) {
                x -= a[i]/2;
                ans++;
            }else{
                y -= (a[i] - x * 2);
                x = 0;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}