#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,kk,p[10][maxn],pos[10][maxn],cnt,head[maxn],dis[maxn];
int f[maxn];
bool exist[maxn];
struct Edge{
    int to;
    int nxt;
}a[maxn*maxn];
void add(int x,int y) {
    // cout<<"from "<<x<<" to "<<y<<endl;
    a[++cnt]=(Edge){y,head[x]};
    head[x]=cnt;
}
int getans(int id) {
    if(f[id]) return f[id];
    int ret=1;
    for(int i=head[id];i;i=a[i].nxt) 
        ret=max(ret,getans(a[i].to)+1);
    return f[id]=ret;
}
int main(){
    cin>>n>>kk;
    for(int i=1;i<=kk;i++) {
        for(int j=1;j<=n;j++) {
            cin>>p[i][j];
            pos[i][p[i][j]]=j;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) {     // i -> j
            if(i==j) continue;
            bool yes=true;
            for(int k=1;k<=kk;k++) {
                if(pos[k][p[1][i]]<pos[k][p[1][j]]) {
                    yes=false;
                    break;
                }
            }
            if(yes) {
                add(p[1][j],p[1][i]);
                exist[p[1][i]]=exist[p[1][j]]=true;
            }
        }
    }
    int ans=1;
    for(int i=1;i<=n;i++) {
        if(exist[p[1][i]]) {
            ans=max(ans,getans(p[1][i]));
        }
    }
    cout<<ans<<endl;
    return 0;
}