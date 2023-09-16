#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t,a,b,c,dest,ans,step[maxn];
inline int id(int x,int y) {
    return x*200+y;
}
void dfs(int x,int y,int ste){
    // cout<<":"<<x<<' '<<y<<' '<<ste<<endl;
    if(x==dest&&y==dest) {
        ans=min(ans,ste);
        return;
    }
    if(ste>step[id(x,y)]) return;
    if(ste+1>ans) return;
    for(int i=1;i<=min(x,c);i++) {
        int tx=x-i, ty=y+i, tid=id(tx,ty);
        if(step[tid]==-1||step[tid]>ste+1){
            step[tid]=ste+1;
            dfs(tx,ty,ste+1);
        }
    }
    for(int i=1;i<=min(y,c);i++) {
        int tx=x+i, ty=y-i, tid=id(tx,ty);
        if(step[tid]==-1||step[tid]>ste+1){
            step[tid]=ste+1;
            dfs(tx,ty,ste+1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        memset(step,-1,sizeof(step));
        cin>>a>>b>>c;
        a*=2, b*=2, c*=2;
        dest=(a+b)/2;
        step[id(a,b)]=0;
        ans=INT_MAX;
        dfs(a,b,0);
        cout<<ans<<endl;
    }
    return 0;
}