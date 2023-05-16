#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int t,n,cnt,head[maxn];
ll dis1[maxn],dis2[maxn],dep[maxn],dis[maxn];
ll k,c;
struct Edge{
    int to;
    int nxt;
}a[maxn<<1];
void add(int x,int y) {
    a[++cnt]=(Edge){y,head[x]};
    head[x]=cnt;
}
void dfs(int x,int fa,ll dis[]) {
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to!=fa){
            dis[a[i].to]=dis[x]+k;
            dfs(a[i].to,x,dis);
        }
    }
}
void getdep(int x,int fa) {
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to!=fa){
            dep[a[i].to]=dep[x]+1;
            getdep(a[i].to,x);
        }
    }
}
int main() {
    cin>>t;
    while(t--) {
        cnt=0;
        for(int i=1;i<=n;i++) dis[i]=head[i]=dis1[i]=dis2[i]=dep[i]=0;

        cin>>n>>k>>c;
        for(int i=1;i<=n-1;i++) {
            int x,y;
            cin>>x>>y;
            add(x,y);
            add(y,x);
        }

        dep[1]=0;
        getdep(1,-1);
        int d1=1, d2=1;
        dis[1]=0;
        dfs(1,-1,dis);
        for(int i=1;i<=n;i++) {
            if(dis[i]>dis[d1])
                d1=i;
        }
        dis1[d1]=0;
        dfs(d1,-1,dis1);
        for(int i=1;i<=n;i++) {
            if(dis1[i]>dis1[d2])
                d2=i;
        }
        dis2[d2]=0;
        dfs(d2,-1,dis2);
        ll ans=0;
        for(int i=1;i<=n;i++) 
            ans=max(ans,max(dis1[i],dis2[i])-dep[i]*c);
        cout<<ans<<endl;
    }
    return 0;
}