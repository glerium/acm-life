#include <bits/stdc++.h>
using namespace std;
struct Pair {
    int i;
    int x;
    bool operator<(const Pair& rhs)const{
        return x > rhs.x;
    }
};
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n+5), f(n+5);
    for(int i=1;i<=n;i++) cin>>a[i];
    priority_queue<Pair> q;
    for(int i=1;i<=n;i++) q.push({i, a[i]});
    int sel = 0;
    while(true) {
        auto now = q.top(); q.pop();
        int delta = min(k - sel, m);
        sel += delta;
        f[now.i] = delta;
        if(k == sel)
            break;
    }
    int price_delta = 0;
    long long ans = 0;
    for(int i=1;i<=n;i++) {
        ans += (a[i] + price_delta) * 1ll * f[i];
        price_delta += f[i];
    }
    cout << ans << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}