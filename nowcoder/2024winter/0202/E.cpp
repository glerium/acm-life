#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=107;
int t,n,m,a[maxn],u[maxn],v[maxn],r[maxn],ans;
void dfs(int x) {
    if(x>m) {
        int rk=1;
        rep(i,1,m) {
            if(r[i]==1) a[u[i]]+=3;
            else if(r[i]==2) a[v[i]]+=3;
            else a[u[i]]++, a[v[i]]++;
        }
        rep(i,1,n) rk+=a[i]>a[1];
        ans=min(ans,rk);
        rep(i,1,m) {
            if(r[i]==1) a[u[i]]-=3;
            else if(r[i]==2) a[v[i]]-=3;
            else a[u[i]]--, a[v[i]]--;
        }
        return;
    }
    for(int i=1;i<=3;i++) {
        r[x]=i;
        dfs(x+1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>m;
        rep(i,1,n) cin>>a[i];
        rep(i,1,m) cin>>u[i]>>v[i];
        ans=114514;
        dfs(1);
        cout<<ans<<endl;
    }
}