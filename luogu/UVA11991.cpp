#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,m; cin >> n >> m;
    if(cin.eof()) exit(0);
    map<int,vector<int>> mp;
    rep(i,1,n) {
        int x; cin >> x;
        mp[x].push_back(i);
    }
    rep(i,1,m) {
        int k,v; cin >> k >> v;
        if(!mp.count(v) || mp[v].size() < k) cout << 0 << endl;
        else cout << mp[v][k-1] << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(1)
        solve();
    return 0;
}
