#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int to[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void solve() {
    int n,m; cin >> n >> m;
    int bx,by; cin >> bx >> by;
    int k; cin >> k;
    vector<pair<int,int>> a(k);
    const int fis = (1 << k) - 1;
    rep(i,0,k-1) cin >> a[i].first >> a[i].second;
    set<array<int,3>> st;
    queue<array<int,4>> que;
    que.push({bx, by, 0, 0});
    st.insert({bx, by, 0});
    int ans = 114514;
    while(!que.empty()) {
        auto [x, y, s, step] = que.front();
        que.pop();
        if(s == fis) {
            ans = min(ans, step + abs(x - bx) + abs(y - by));
            continue;
        }
        rep(i,0,3) {
            int tx = x + to[i][0],
                ty = y + to[i][1];
            int ts = s;
            rep(j,0,k-1) {
                if(a[j] == make_pair(tx, ty)) {
                    ts |= 1 << j;
                }
            }
            if(!st.count({tx, ty, ts})) {
                que.push({tx, ty, ts, step + 1});
                st.insert({tx, ty, ts});
            }
        }
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
// 64 位输出请用 printf("%lld")