#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=2e5+10;
int t,n,head[maxn],ct,f[maxn],sz[maxn];
struct Edge{
    int to,nxt;
}a[maxn];
void add(int x,int y) {
    a[++ct]={y,head[x]};
    head[x]=ct;
}
int dp(int x) {
    f[x]=0;
    sz[x]=1;
    int mx=-1,mxi=0;
    for(int i=head[x];i;i=a[i].nxt) {
        dp(a[i].to);
        sz[x]+=sz[a[i].to];
        f[x]+=f[a[i].to];
        if(2*sz[a[i].to]-f[a[i].to]>mx) {
            mx=2*sz[a[i].to]-f[a[i].to];
            mxi=a[i].to;
        }
    }
    int s=sz[x];
    if(mxi>s) f[x]=f[mxi]+2*(sz[x]-sz[mxi]-1);
    else f[x]=(sz[x]-1)/2*2;
    return f[x]/2;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        ct=0;
        rep(i,1,n) head[i]=0;
        rep(i,2,n) {
            int tmp; cin>>tmp;
            add(tmp,i);
        }
        cout<<dp(1)<<endl;
    }
    return 0;
}