#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll INF = 0x3f3f3f3f;
void solve() {
    int n; cin >> n;
    map<int,int> mx, my;
    rep(i,1,n) {
        int x, y; cin >> x >> y;
        mx[x]++;
        my[x + y]++;
    }
    int x, y;
    for(auto [k, v] : mx) {
        if(v % 2 == 1)
            x = k;
    }
    for(auto [k, v] : my) {
        if(v % 2 == 1)
            y = k;
    }
    cout << x << ' ' << y - x << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
