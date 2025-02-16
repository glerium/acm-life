#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n, m; cin >> n >> m;
    // int a[n+5] = {}, b[m+5] = {};
    multiset<ll> sta, stb;
    rep(i,1,n) {
        int x; cin >> x;
        sta.insert(x);
    }
    rep(i,1,m) {
        int x; cin >> x;
        stb.insert(x);
    }
    for(auto i : stb) {
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            auto now = q.front(); q.pop();
            if(sta.count(now)) {
                sta.erase(sta.find(now));
                continue;
            }
            if(now < *sta.begin()) {
                cout << "No" << endl;
                return;
            }
            int x = now / 2, y = now - x;
            if(x < 1 || y < 1) {
                cout << "No" << endl;
                return;
            }
            if(q.size() > sta.size()) {
                cout << "No" << endl;
                return;
            }
            q.push(x);
            q.push(y);
        }
    }
    if(sta.size() == 0) {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
