#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
constexpr int maxn = 5e5+10;
int n,m,s,head[maxn],ct,fa[maxn],dep[maxn];
map<int,int> mp;
struct Edge {
    int to, nxt;
}a[maxn << 1];
void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}
void dfs(int x, int from) {
    fa[x] = from;
    dep[x] = dep[from] + 1;
    mp[dep[x]]++;
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to == from)
            continue;
        dfs(a[i].to, x);
    }
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n-1;i++) {
        int x, y; cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    int sd=0, kd=0;
    for(int i=1;i<=n;i++)
        sd = max(sd, dep[i]);
    for(auto [x,y] : mp) 
        kd = max(kd, y);
    int x, y; cin >> x >> y;
    int ans = 0;
    while(x != y) {
        if(dep[x] < dep[y]) {
            y = fa[y];
            ans++;
        }
        else if(dep[x] > dep[y]) {
            x = fa[x];
            ans += 2;
        }else{
            x = fa[x];
            y = fa[y];
            ans += 3;
        }
    }
    cout << sd << endl << kd << endl << ans << endl;
}
