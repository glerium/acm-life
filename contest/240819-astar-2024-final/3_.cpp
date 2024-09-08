#include <iostream>
#include <queue>
#include <map>
#include <cstring>

using namespace std;
constexpr int maxm = 1e3+10;
constexpr int maxn = 1.5e6+10;
typedef long long ll;
int n,x1,y1,x2,y2,blk[maxm][maxm],blk_ct;

inline pair<int,int> dec(int x) {
    return make_pair(x/1001, x%1001);
}
struct Edge{
    int to,nxt;
    ll dis;
}a[maxn<<2];
struct State{
    int x;
    ll dis;
    bool operator<(const State& rhs)const{
        return dis > rhs.dis;
    }
};
int head[maxn], ct;
ll dis[maxn];
priority_queue<State> q;
void add(int x,int y,ll dis) {
    a[++ct] = {y, head[x], dis};
    head[x] = ct;
}
bool ice[maxm][maxm];
constexpr int to[4][2] {{-1,0},{1,0},{0,1},{0,-1}};
void dfs(int x,int y,int id) {
    blk[x][y] = id;
    for(int i=0;i<4;i++) {
        int tx=x+to[i][0], ty=y+to[i][1];
        if(ice[tx][ty]) continue;
        dfs(tx,ty,id);
    }
}
int main() {
    cin >> n >> x1 >> y1 >> x2 >> y2;
    for(int i=1;i<=n;i++) {
        int x,y; cin>>x>>y;
        ice[x][y] = true;
    }
    for(int i=1;i<=1e3;i++) {
        for(int j=1;j<=1e3;j++) {
            if(!blk[i][j] && !ice[i][j])
                dfs(i, j, ++blk_ct);
        }
    }
    
    return 0;
}