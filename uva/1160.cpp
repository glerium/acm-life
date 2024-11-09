#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5+10;
struct MFS {
    int fa[maxn];
    void init() {
        for(int i=1;i<=1e5;i++)
            fa[i] = i;
    }
    int find(int x) {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        fa[x] = y;
    }
} mfs;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    while(scanf("%d", &x) == 1) {
        mfs.init();
        int ans = 0;
        while(x != -1) {
            scanf("%d", &y);
            if(mfs.find(x) != mfs.find(y))
                mfs.merge(x, y);
            else ans++;
            scanf("%d", &x);
        }
        printf("%d\n", ans);
    }
}
