#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
constexpr int maxm = 1e6+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int a[n+5] = {}, b[n+5] = {};
    rep(i,1,n) cin >> a[i] >> b[i];
    int f[maxm] = {};
    bool have[maxm] = {};
    rep(i,1,n) have[a[i]] = true;
    int bpos[maxm] = {};
    rep(i,1,n) bpos[a[i]] = b[i];
    f[0] = have[0];
    rep(i,1,1e6) {
        if(have[i]) {
            if(i - bpos[i] - 1 >= 0)
                f[i] = f[i - bpos[i] - 1] + 1;
            else
                f[i] = 1;
        } else {
            f[i] = f[i-1];
        }
    }
    int ans = 0;
    rep(i,0,1e6) ans = max(ans, f[i]);
    cout << n - ans << endl;
    return 0;
}