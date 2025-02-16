#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    string s[n+5];
    rep(i,1,n) {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    vector<pair<int,int>> src;
    rep(i,1,n) rep(j,1,n) if(s[i][j] == '1') src.push_back({i,j});
    vector<pair<int,int>> tgt;
    rep(i,1,n/2) rep(j,1,n/2) tgt.push_back({i,j});
    // int ct = 0;
    vector<array<int,4>> ans;
    // assert(src.size() == n*n/4);
    // assert(tgt.size() == n*n/4);
    set<pair<int,int>> done;
    rep(i,0,n*n/4-1) {
        int x = src[i].first, y = src[i].second;
        int tx = tgt[i].first, ty = tgt[i].second;
        while(x != tx || y != ty) {
            if(x > tx && !done.count({x-1, y})) {
                ans.push_back({x, y, x-1, y});
                swap(s[x][y], s[x-1][y]);
                x--;
            }else if(x < tx && !done.count({x+1, y})) {
                ans.push_back({x, y, x+1, y});
                swap(s[x][y], s[x+1][y]);
                x++;
            }
            if(y > ty && !done.count({x, y-1})) {
                ans.push_back({x, y, x, y-1});
                swap(s[x][y], s[x][y-1]);
                y--;
            }else if(y < ty && !done.count({x, y+1})) {
                ans.push_back({x, y, x, y+1});
                swap(s[x][y], s[x][y+1]);
                y++;
            }
        }
        done.insert({x, y});
    }
    cout << ans.size() << endl;
    for(auto [a,b,c,d] : ans) {
        cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
