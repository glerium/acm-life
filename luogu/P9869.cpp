#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef pair<int,int> pii;
constexpr int maxn=2e5+10;
constexpr int T=1e7, F=-1e7, U=0;
int c,t,n,m,op[maxn],clr[maxn];
int head[maxn],cnt;
struct Edge{
    int to,nxt,type;
}a[maxn];
set<pii> ste;
bitset<maxn> isu,vis,ing;
bool known(int x) {
    return (x==T||x==F||x==U)?true:false;
}
void add(int x,int y,int z) {
    // printf("Add %d -> %d\n",x,y);
    a[++cnt]={y,head[x],z};
    head[x]=cnt;
}
int dfs(int x) {
    if(vis[x]) return op[x];
    vis[x]=true;
    if(known(op[x])) return op[x];
    if(x==-op[x]) return op[x]=U;
    const int to=abs(op[x]);
    if(known(dfs(to))) {
        op[x]=op[to]*(op[to]>0?1:-1);
    }
    return op[x];
}
int dfs2(int x) {
    if(vis[x]) return clr[x];
    vis[x]=true;
    for(int i=head[x];i;i=a[i].nxt) {
        const int ncolor=clr[x]*a[i].type;
        const int to=a[i].to;
        printf("%d clr %d, to %d clr %d\n",x,clr[x],to*a[i].type,clr[to]);
        if(vis[to]) {
            if(ncolor!=clr[to])
                return clr[to]=clr[x]=U;
            if(clr[to]==U)
                return clr[x]=U;
        }else{
            clr[to]=ncolor;
            if(dfs2(to)==U)
                clr[x]=U;
        }
    }
    // printf("clr[%d]=%d\n",x,clr[x]);
    if(clr[x]==-x) return clr[x]=U;
    return clr[x];
}
int main() {
    ios::sync_with_stdio(false);
    cin>>c>>t;
    while(t--) {
        cin>>n>>m;
        ste.clear();
        isu.reset(); vis.reset(); ing.reset();
        rep(i,1,n) op[i]=i;
        rep(i,1,n) head[i]=0;
        cnt=0;
        rep(i,1,m) {
            char o; int x,y;
            cin>>o;
            if(o=='-'||o=='+') {
                cin>>x>>y;
                op[x]=op[y]*(o=='+'?1:-1);
            }else{
                cin>>x;
                if(o=='T') op[x]=T;
                else if(o=='F') op[x]=F;
                else op[x]=U;
            }
        }
        // rep(i,1,n) cout<<":"<<op[i]<<endl;
        rep(i,1,n) dfs(i);
        // rep(i,1,n) cout<<":"<<op[i]<<endl;
        vis.reset();
        rep(i,1,n) if(known(op[i])) clr[i]=op[i], vis[i]=true;
        rep(i,1,n) {
            if(known(op[i])) continue;
            if(op[i]>0) {
                add(i,op[i],1);
                add(op[i],i,1);
            }else{
                add(i,-op[i],-1);
                add(-op[i],i,-1);
            }
        }
        rep(i,1,n) {
            if(!vis[i]){
                clr[i]=T;
                dfs2(i);
            }
        }
        rep(i,1,n) cout<<":"<<clr[i]<<endl;
        int ans=0;
        rep(i,1,n) ans+=clr[i]==U;
        cout<<ans<<endl;
    }
    return 0;
}