#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int ans = 1;
    int mx = 0;
    int n_ = n;
    bool flag = true;
    for(int i=2; i*i<=n_; i++) {
        if(n % i == 0) {
            int ct = 0;
            while(n % i == 0) {
                n /= i;
                ct++;
            }
            if(mx != 0 && ct != mx || (1 << __lg(ct) != ct))
                flag = false;
            mx = max(mx, ct);
            ans *= i;
        }
    }
    if(n != 1) {
        ans *= n;
        if(mx != 0 && 1 != mx)
            flag = false;
        mx = max(mx, 1);
    }
    int ansv = 0;
    while((1 << ansv) < mx) ansv++;
    cout << ans << ' ' << ansv + (!flag) << endl;
}