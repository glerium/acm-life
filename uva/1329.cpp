#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
constexpr int maxn = 1e5+10;
struct MFS {
    int fa[maxn];
    int dis[maxn];
    void init(int x) {
        for(int i=1;i<=x;i++) {
            fa[i] = i;
            dis[i] = 0;
        }
    }
    int find(int x) {
        if(fa[x] == x) return x;
        int father = find(fa[x]);
        dis[x] += dis[fa[x]];
        fa[x] = father;
        return fa[x];
    }
    void merge(int x, int y) {
        fa[x] = y;
        dis[x] = abs(x - y) % 1000;
    }
} mfs;
void solve() {
    int n; cin >> n;
    mfs.init(n);
    char op; int x, y;
    cin >> op;
    while(op != 'O') {
        if(op == 'E') {
            cin >> x;
            mfs.find(x);
            cout << mfs.dis[x] << endl;
        }else{
            cin >> x >> y;
            mfs.merge(x, y);
        }
        cin >> op;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}