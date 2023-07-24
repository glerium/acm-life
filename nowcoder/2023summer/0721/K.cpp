#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,a[maxn],b[maxn],f[maxn][4],s[maxn];
signed main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) {
        if(b[i]) f[i][1] = max(max(f[i-1][0],f[i-1][1]),f[i-1][2]) + a[i];
        f[i][0]=max(max(f[i-1][0],f[i-1][1]),max(f[i-1][2],f[i-1][3]));
        if(b[i+1]) {
            f[i][3]=max(max(f[i-1][1],f[i-1][0]),f[i-1][3]) + a[i];
        }
        if(b[i-1]) {
            for(int j=i-1;b[j];j--) {
                f[i][2]=max(f[i][2],max(f[j-1][0],f[j-1][1])+s[i]-s[j]);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=3;j++)
    //         cout<<f[i][j]<<' ';
    //     cout<<endl;
    // }
    cout<<max(max(f[n][0],f[n][1]),max(f[n][2],f[n][3]))<<endl;
    return 0;
}