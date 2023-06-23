#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,s,dep[maxn],fa[maxn][23];
int lg;
vector<vector<int>> a;
void dfs(int x,int from){
    for(auto i : a[x]){
        if(i!=from) {
            dep[i]=dep[x]+1;
            fa[i][0]=x;
            dfs(i,x);
        }
    }
}
void init() {
    dfs(s,0);
    lg=log2(n+5);
    for(int i=1;i<=lg;i++) {
        for(int j=1;j<=n;j++) {
            fa[j][i]=fa[fa[j][i-1]][i-1];
        }
    }
}
int query(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=lg;i>=0&&dep[x]>dep[y];i--) {
        if(fa[x][i]&&dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    }
    // printf(":%d %d\n",x,y);
    if(x==y) return x;
    for(int i=lg;i>=0&&fa[x][0]!=fa[y][0];i--) {
        if(fa[x][i]!=fa[y][i]) {
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m>>s;
    a.resize(n+10);
    for(int i=1;i<=n-1;i++) {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    init();
    for(int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;
        cout<<query(x,y)<<endl;
    }
    return 0;
}