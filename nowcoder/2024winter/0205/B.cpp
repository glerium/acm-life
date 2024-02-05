#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e5+10;
int t,n,m,k,a[307][307][2];
int main() {
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++) {
        int x,y; cin>>x>>y;
        a[x][y][0]=true;
        a[x][y][1]=true;
        a[x-1][y][0]=true;
        a[x][y-1][1]=true;
    }
    int ans=0;
    for(int i=0;i<=300;i++) {
        for(int j=0;j<=300;j++)
            ans+=a[i][j][0]+a[i][j][1];
    }
    cout<<ans<<endl;
}