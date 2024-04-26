#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn = 1e5+10;
constexpr int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,a[107][107],k,x[maxn],y[maxn],sx,sy,dis[107][107];
void dfs(int x,int y) {
    for(int i=0;i<4;i++) {
        int dx=x+to[i][0], dy=y+to[i][1];
        if(dx < 1 || dy < 1 || dx > m || dy > n) continue;
        if(dis[dx][dy] <= dis[x][y] + 1) continue;
        if(a[dx][dy] == 0) continue;
        dis[dx][dy] = dis[x][y] + 1;
        dfs(dx, dy);
    }
}
map<int,vector<int>> mp;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep(i,1,n) rep(j,1,m) {
        cin >> a[i][j];
        if(a[i][j] == 2) sx=i, sy=j;
    }
    memset(dis,0x3f,sizeof(dis));
    dis[sx][sy] = 0;
    dfs(sx,sy);
    int k; cin>>k;
    for(int i=1;i<=k;i++) {
        int x,y; cin>>y>>x;
        if(dis[x][y] == 0x3f3f3f3f) continue;
        mp[dis[x][y]].push_back(i);
    }
    for(auto [x,y] : mp) {
        if(y.size() >= 2) continue;
        cout << y[0] << ' ' << x << endl;
        return 0;
    }
    cout << "No winner." << endl;
    return 0;
}