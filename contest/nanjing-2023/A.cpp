#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef pair<int,int> pii;
constexpr int maxn=1e3+10;
constexpr int a[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int t,n,m,bcnt;
char s[maxn][maxn];
bool vis[maxn][maxn], win[maxn];
vector<pii> b[maxn];
set<pii> bb[maxn];
pii operator-(const pii lhs, const pii rhs){
    return {lhs.first-rhs.first, lhs.second-rhs.second};
}
pii operator+(const pii lhs, const pii rhs){
    return {lhs.first+rhs.first, lhs.second+rhs.second};
}
void dfs(int x,int y) {
    if(vis[x][y]) return;
    vis[x][y]=true;
    b[bcnt].push_back({x,y});
    bb[bcnt].insert({x,y});
    for(int i=0;i<4;i++) {
        int tx=x+a[i][0], ty=y+a[i][1];
        if(tx<1||tx>n||ty<1||ty>m) continue;
        if(s[tx][ty]=='O') continue;
        if(vis[tx][ty]) continue;
        dfs(tx,ty);
    }
}
void clear() {
    bcnt=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vis[i][j]=false;
    for(int i=1;i<=n*m;i++) win[i]=true, b[i].clear(), bb[i].clear();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>t;
    while(t--) {
        cin>>n>>m;
        clear();
        for(int i=1;i<=n;i++) cin>>(s[i]+1);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i][j]=='.'&&!vis[i][j]) {
                    bcnt++;
                    dfs(i,j);
                }
            }
        }
        // cout<<"bcnt:"<<bcnt<<endl;
        for(int i=1;i<=bcnt;i++) {
            const pii ori=b[i][0];
            for(int j=1;j<=bcnt;j++) {
                if(i==j) continue;
                if(b[i].size()>b[j].size()) continue;
                for(auto k:b[j]) {
                    bool ok=true;
                    for(auto l:b[i]) {
                        const pii delta=l-ori, mapped=k+delta;
                        if(!bb[j].count(mapped)) {
                            ok=false;
                            break;
                        }
                    }
                    if(ok) {
                        win[i]=false;
                        goto end;
                    }
                }
            end:;
            }
        }
        int ans=0;
        // for(int i=1;i<=bcnt;i++) {
        //     cout<<":"<<b[i].size()<<' '<<win[i]<<endl;
        // }
        for(int i=1;i<=bcnt;i++) if(win[i]) ans+=b[i].size();
        cout<<ans<<endl;
    }
    return 0;
}