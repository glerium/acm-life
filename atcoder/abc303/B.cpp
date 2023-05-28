#include <bits/stdc++.h>
using namespace std;
int n,m,a[101][101];
bool bad[101][101];
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) bad[i][j]=true;
    }
    for(int i=1;i<=m;i++) {
        int last=0,ima;
        for(int j=1;j<=n;j++){
            cin>>ima;
            bad[last][ima]=bad[ima][last]=false;
            last=ima;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) ans+=bad[i][j];
    }
    cout<<ans<<endl;
    return 0;
}