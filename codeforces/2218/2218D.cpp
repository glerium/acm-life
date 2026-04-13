#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
vector<int> pri;
void init() {
    int m = 2e5;
    vector<bool> isp(m+5, true);
    isp[1] = false;
    rep(i,2,m) {
        if(isp[i]) {
            for(int j = i + i; j <= m; j += i) {
                isp[j] = false;
            }
        }
    }
    rep(i,1,m) {
        if(isp[i]) {
            pri.push_back(i);
        }
    }
    // cout << pri.size() << endl;
}
void solve() {
    int n; cin >> n;
    rep(i,1,n) {
        cout << ll(pri[i - 1]) * pri[i] << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}