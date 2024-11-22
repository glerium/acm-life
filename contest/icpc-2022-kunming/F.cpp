#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn = 1e6+10;
int n,b[maxn],head[maxn],ct;
struct Edge {
    int to, nxt;
}a[maxn << 1];
void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}
double ans = 0;
void dfs(int x, int fa) {
    vector<int> vec;
    for(int i=head[x];i;i=a[i].nxt) {
        int to = a[i].to;
        if(to == fa) continue;
        if(fa != -1)
            ans = max(ans, 1.0 * (b[fa] + b[to] + b[x]) * (b[fa] + b[to] + b[x]) / 9 / 4);
        vec.push_back(b[to]);
        dfs(to, x);
    }
    sort(vec.begin(), vec.end());
    for(int i=0;i<int(vec.size()-1);i++) {
        ans = max(ans, 1.0 * (vec[i] + vec[i+1] + b[x]) * (vec[i] + vec[i+1] + b[x]) / 9 / 4);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> b[i];
    rep(i,1,n-1) {
        int x, y; cin >> x >> y;
        add(x, y);
        add(y, x);
        ans = max(ans, 1.0 * (b[x] + b[y]) * (b[x] + b[y]) / 16);
    }
    dfs(1, -1);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}