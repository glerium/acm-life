#include <bits/stdc++.h>
#define endl '\n'

#define rep(i, o, p) for(int i = o; i <= p; i ++ )

using namespace std;
constexpr int maxn = 5e5+10;

int n,m,k;
int busy[maxn],head[maxn], ct;
map<int,vector<int>> ans;
vector<int> visv;
bitset<maxn> v;

struct Edge {
    int to, nxt;
}a[maxn << 1];

void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}

void dfs(int x, int fa) {
    vector<int> yq;
    visv.push_back(x);
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to == fa)
            continue;
        if(v[a[i].to]) continue;
        v[a[i].to] = true;
        yq.push_back(a[i].to);
        if(!busy[a[i].to])
            dfs(a[i].to, x);
    }
    if(yq.size() > 0)
        ans[x] = yq;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i=1;i<=k;i++) {
        int x; cin >> x;
        busy[x] = true;
    }
    for(int i=1;i<=m;i++) {
        int x, y; cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    for(int i=1;i<=n;i++) {
        if(!busy[i]) {
            v[i] = true;
            dfs(i, -1);
            break;
        }
    }
    bool ok = true;
    for(int i=1;i<=n;i++) {
        if(!v[i]) {
            ok = false;
            break;
        }
    }
    if(ok) {
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        for(auto i : visv) {
            if(!ans.count(i))
                continue;
            cout << i << ' ' << ans[i].size() << ' ';
            for(auto j : ans[i])
                cout << j << ' ';
            cout << endl;
        }
    }else{
        cout << "No" << endl;
    }
    return 0;
}