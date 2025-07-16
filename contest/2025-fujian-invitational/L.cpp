#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr int inf = 0x3f3f3f3f;
void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    map<int,int> mp;
    int mn = inf, mx = -inf;
    int ctmaxi = 0;
    rep(i,1,n) {
        mp[a[i]]++;
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        if(mp[a[i]] >= mp[ctmaxi] && a[i] > ctmaxi)
            ctmaxi = a[i];
        if(mp[ctmaxi] == i - 1) {
            cout << max(2 * ctmaxi, mn + mx) << ' ';
        } else {
            cout << mn + mx << ' ';
        }
    }
    cout << endl;
}
int main()
{
    int t; cin >> t;
    while(t--) solve();
    return 0;
}