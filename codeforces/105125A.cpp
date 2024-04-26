#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
struct Compare {
    bool operator()(const set<int> &lhs, const set<int> &rhs) const {
        if(lhs.size() != rhs.size()) return lhs.size() < rhs.size();
        return lhs < rhs;
    }
};
void solve() {
    int n,m; cin>>n>>m;
    map<set<int>,int,Compare> ct;
    while(m--) {
        int x,y,z; cin>>x>>y>>z;
        ct[{x,y,z}]++;
    }
    for(auto [x,y] : ct) {
        if(y & 1) {
            cout << "YES" << endl;
            for(int i=1;i<=n;i++) {
                if(x.count(i)) cout << 1 << ' ';
                else cout << 0 << ' ';
            }
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
