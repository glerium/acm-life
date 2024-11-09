#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
constexpr int maxn = 5e5+10;
int n,m,s,head[maxn],ct,fa[maxn][30],dep[maxn];
struct Edge {
    int to, nxt;
}a[maxn << 1];
void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}
void dfs(int x, int from) {
    fa[x][0] = from;
    dep[x] = dep[from] + 1;
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to == from)
            continue;
        dfs(a[i].to, x);
    }
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s;
    for(int i=1;i<=n-1;i++) {
        int x, y; cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(s, 0);
    for(int j=1;j<=20;j++) {
        for(int i=1;i<=n;i++) {
            fa[i][j] = fa[fa[i][j-1]][j-1];
        }
    }
    while(m--) {
        int x, y; cin >> x >> y;
        if(dep[x] < dep[y])
            swap(x, y);
        for(int i=20; i>=0&&dep[x]>dep[y]; i--) {
            if(dep[fa[x][i]] >= dep[y])
                x = fa[x][i];
        }
        if(x == y) {
            cout << x << endl;
            continue;
        }
        for(int i=20; i>=0; i--) {
            if(fa[x][i] != fa[y][i]) {
                x = fa[x][i];
                y = fa[y][i];
            }
        }
        cout << fa[x][0] << endl;
    }
    return 0;
}