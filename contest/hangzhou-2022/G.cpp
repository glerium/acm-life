#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int maxn=2e5+10;
int t,n,m,head[maxn],cnt,d[maxn];
// struct Edge{
//     int to,nxt;
// }a[maxn];
void add(int x,int y){
    d[x]++;
    d[y]++;
    // a[++cnt]={y,head[x]};
    // head[x]=cnt;
}
// int dfs(int x,int from){
//     int sz=1;
//     for(int i=head[x];i;i=a[i].nxt) {
//         if(a[i].to==from) continue;
//         sz+=dfs(a[i].to, x);
//     }
//     return sz;
// }
bool check_cycle() {
    rep(i,1,n) if(d[i]!=2) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>m;
        rep(i,1,n) d[i]=0;
        rep(i,1,m) {
            int x,y; cin>>x>>y;
            add(x,y);
            // add(y,x);
        }
        if(m==n-1) puts("YES");
        else if(check_cycle()) {
            puts("YES");
        }
        else puts("NO");
    }
}