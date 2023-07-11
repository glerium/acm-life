#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int n,r,mp[maxn][maxn],a[maxn][maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>r;
    r--;
    for(int i=1;i<=n;i++) {
        int x,y,v;
        x++,y++;
        cin>>x>>y>>v;
        mp[x][y]=v;
    }
    for(int i=1;i<=5001;i++) {
        for(int j=1;j<=5001;j++) {
            a[i][j]=a[i][j-1]+a[i-1][j]-a[i-1][j-1]+mp[i][j];
        }
    }
    int ans=-1;
    // i-r+1,j-r+1 -> i,j
    for(int i=1;i<=5001;i++) {
        for(int j=1;j<=5001;j++) {
            if(i-r+1<0||j-r+1<0) continue;
            ans=max(ans,a[i][j]-a[i][j-r]-a[i-r][j]+a[i-r][j-r]);
        }
    }
    cout<<ans<<endl;
    return 0;
}