#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
constexpr int maxn = 1e5+10;
int n,a[maxn],f[maxn],fa[maxn],ans[maxn];
int query(int x) {
    if(f[x] == x) return x;
    return f[x] = query(f[x]);
}
void dfs(int x, int y) {
    if(query(x) == query(y)) {        // found cycle
        int ct = 1;
        for(int i=y;i!=x;i=fa[i]) ct++;
        for(int i=y;i!=x;i=fa[i]) ans[i] = ct;
        ans[x] = ct;
    }else{
        fa[x] = y;
        f[query(x)] = query(y);
    }
}
int main() {
    // freopen("out.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
        f[i] = i;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        dfs(i, a[i]);
    }
    for(int i=1;i<=n;i++) {
        if(!ans[i]) {
            int ct=0, j=i;
            for(;!ans[j];j=fa[j])
                ct++;
            ans[i] = ans[j] + ct;
        }
    }
    for(int i=1;i<=n;i++)
        cout << ans[i] << endl;
    return 0;
}