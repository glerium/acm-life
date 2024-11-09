#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
constexpr int maxn = 1e5+10;
int n,a[maxn],fa[maxn],ans=0x3f3f3f3f;
int tmp = 0;
int query(int x) {
    tmp++;
    if(fa[x] == x) return x;
    return query(fa[x]);
}
void dfs(int x, int y) {
    int a = query(x), b = query(y);
    if(a == b) {        // found cycle
        int ct = 1;
        for(int i=y;i!=x;i=fa[i]) ct++;
        ans = min(ans, ct);
    }else{
        fa[x] = y;
    }
}
int main() {
    // freopen("out.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
        fa[i] = i;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        dfs(i, a[i]);
    }
    cout << ans << endl;
    cout << tmp << endl;
    return 0;
}