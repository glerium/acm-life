#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,k,a[10][maxn],f[maxn],pos[10][maxn];
bool vis[maxn][maxn];
int main(){
    cin>>n>>k;
    for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) {
        cin>>a[i][j];
        pos[i][a[i][j]]=j;
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        int mx=0;
        for(int j=1;j<i;j++) {
            bool yes=true;
            for(int kk=1;kk<=k;kk++) {
                if(pos[kk][a[1][i]]<pos[kk][a[1][j]]) {
                    yes=false;
                    break;
                }
            }
            if(yes) mx=max(mx,f[j]);
        }
        f[i]=mx+1;
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}