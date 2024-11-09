#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
#define ll long long 

const int N = 5e5 + 10;

int f[N];

int u[N], v[N];

int find(int x){
    if(x == f[x]) return x;
    return f[x] = find(f[x]);
}

void ch(int x, int y){
    int fx = find(x), fy = find(y);
    f[fy] = fx;
}

int tmp[N];

int tot = 0;

vector<int> e[N], val[N];

void dfs(int ps, int now, int pos){
    if(now == pos){
        sort(tmp + 1, tmp + tot + 1);
        rep(j, 1, tot) cout << tmp[j] << " ";
        return ;
    }
    rep(i, 0, e[now].size() - 1){
        int y = e[now][i], v = val[now][i];
        if(y == ps) continue;
        tmp[++ tot] = v;
        dfs(now, y, pos);
        tot --;
    }
}


void solve() {
    tot = 0;
    int n, m;
    cin >> n >> m;
    rep(i, 1 ,n) f[i] = i;
    rep(i, 1, n) e[i].clear();
    rep(i, 1, n) val[i].clear();
    rep(i, 1, m) cin >> u[i] >> v[i];
    rep(i, 1, m) {
        if(find(v[i]) == find(u[i]) ){
            dfs(0, u[i], v[i]);
            cout << i << endl;
            return ;
        }
        else ch(u[i], v[i]);
        e[u[i]].push_back(v[i]);
        val[u[i]].push_back(i);
        e[v[i]].push_back(u[i]);
        val[v[i]].push_back(i);
    }
    cout << -1 << endl;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}