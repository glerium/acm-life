#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5+10;
int n,fa[maxn],dis[maxn],ans=0x3f3f3f3f;
int query(int x) {
    if(fa[x] == x) return x;
    int father = fa[x];
    fa[x] = query(fa[x]);
    dis[x] = dis[x] + dis[father];
    return fa[x];
}
void add(int x, int y) {
    int a = query(x);
    int b = query(y);
    if(a == b) ans = min(ans, dis[x] + dis[y] + 1);
    else {
        fa[b] = a;
        dis[y] = dis[x] + 1;
    }
}
int main() {
    cin >> n;
    for(int i=1;i<=n;i++) fa[i] = i;
    for(int i=1;i<=n;i++) {
        int tmp; cin >> tmp;
        add(tmp, i);
    }
    cout << ans << endl;
    return 0;
}