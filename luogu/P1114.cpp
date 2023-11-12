#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=1e6+10;
constexpr int delta=3e5;
int n,a[maxn],f[maxn],p[maxn][2];
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n) cin>>a[i];
    rep(i,0,1e6) {
        p[i][0]=1e9;
        p[i][1]=-1;
    }
    p[0+delta][0]=p[0+delta][1]=0;
    rep(i,1,n) {
        if(a[i]==0) f[i]=f[i-1]+1;
        else f[i]=f[i-1]-1;
        p[f[i]+delta][0]=min(p[f[i]+delta][0],i);
        p[f[i]+delta][1]=max(p[f[i]+delta][1],i);
    }
    int ans=0;
    rep(i,0,1e6) {
        if(p[i][1]==-1) continue;
        ans=max(p[i][1]-p[i][0],ans);
    }
    cout<<ans<<endl;
    return 0;
}