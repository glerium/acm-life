#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
constexpr int maxn = 1e6+10;
int n,fa[maxn],in[maxn],ct,head[maxn],dep[maxn];
set<pair<int,int>> vis;
struct Edge {
    int to,nxt;
}a[maxn];
void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}

void dfs(int x) {
    for(int i=head[x];i;i=a[i].nxt) {
        dep[a[i].to] = dep[x] + 1;
        dfs(a[i].to);
    }
}
bool cmp(int x, int y) {
    return dep[x] < dep[y];
}

void solve() {
    int n; cin >> n;
    memset(fa, 0, sizeof(fa[0]) * (n+5));
    memset(in, 0, sizeof(in[0]) * (n+5));
    memset(dep, 0, sizeof(dep[0]) * (n+5));
    memset(head, 0, sizeof(head[0]) * (n+5));
    vis.clear();
    ct = 0;
    for(int i=2;i<=n;i++) {
        cin >> fa[i];
        add(fa[i], i);
        in[fa[i]] = true;
    }
    vector<int> leaf;
    for(int i=1;i<=n;i++) {
        if(!in[i])
            leaf.push_back(i);
    }
    dep[1] = 0;
    dfs(1);
    sort(leaf.begin(), leaf.end(), cmp);
    int ans = 0;
    for(auto i : leaf) {
        int len = 0;
        // vis.insert({fa[i], i});
        int now = i;
        while(!vis.count({fa[now], now}) && fa[now]) {
            vis.insert({fa[now], now});
            now = fa[now];
            len++;
        }
        // cout << len << endl;
        ans = max(ans, len);
    }
    // for(int i=1;i<=n;i++)
    //     cout << dep[i] << ' ';
    // cout << endl;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}