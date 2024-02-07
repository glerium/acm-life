#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=60;
int t,n,head[maxn],ct,dep[maxn];
bool f[maxn][maxn];
struct Edge{
    int to,nxt;
}a[maxn];
bitset<maxn> v;
vector<int> vis;
struct Cond{
    int x,y,z;
}c[maxn];
void add(int x,int y) {
    a[++ct]={y,head[x]};
    head[x]=ct;
}
bool dfs(int x,int fa) {
    v[x]=true;
    vis.push_back(x);
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to==fa) continue;
        if(v[a[i].to]) return false;
        if(!dfs(a[i].to,x)) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        v.reset();
        vis.clear();
        for(int i=1;i<=n;i++) dep[i]=0;
        for(int i=1;i<=n;i++) cin>>c[i].x>>c[i].y>>c[i].z;
        for(int i=1;i<=n;i++) {
            if(c[i].z) {
                add(c[i].x,c[i].y);
            }
        }
        for(int i=1;i<=n;i++) {
            if(!v[i]) {
                vis.clear();
                int flag = dfs(i,-1);
                if(!flag) {
                    puts("No");
                    goto end;
                }
                for(int x=0;x<vis.size();x++) {
                    for(int y=x+1;y<vis.size();y++) {
                        if(dep[x]<dep[y])
                            f[x][y]=true;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) {
            
        }

end:    ;
    }
}