#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int s,k; cin >> s >> k;
    if(s % k == 0) {
        cout << k << endl;
        return;
    }
    if(s >= k * k) {
        cout << max(1, k - 2) << endl;
        return;
    }
    bool vis1[s+5] = {}, vis2[s+5] = {};
    vis1[0] = true;
    int dir = 1;        // 1 forward; -1 back
    while(true) {
        queue<int> q;
        rep(i,0,s) {
            if(vis1[i])
                q.push(i);
        }
        while(!q.empty()) {
            int now = q.front(); q.pop();
            int to = now + dir * k;
            if(to <= s && to >= 0 && !vis1[to]) {
                vis1[to] = true;
                q.push(to);
            }
        }
        if(vis1[s]) {
            cout << k << endl;
            return;
        }
        dir = -dir;
        k = max(1, k - 1);
        memset(vis2, 0, sizeof(vis2));
        rep(i,0,s) {
            if(!vis1[i]) continue;
            int to = i + dir * k;
            if(to <= s && to >= 0) {
                vis2[to] = true;
            }
        }
        memcpy(vis1, vis2, sizeof(vis1));
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
