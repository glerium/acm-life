#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+9;
typedef long long ll;
int n,m,kkk,p[maxn];
ll s[maxn],f[maxn],mx[maxn];
ll getsum(int x,int y) {
    return s[y]-s[x-1];
}
int main(){
    cin>>n>>m>>kkk;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+p[i];
    // for(int i=1,j=m;j<=n;i++,j++) f[1][i]=getsum(i,j);
    // f[i][j]: 选择i个，开头为j的最大值
    for(int i=1;i<=kkk;i++) {
        for(int j=1,k=j+m-1;k<=n;j++,k++){
            if(j-m<0) f[j]=getsum(j,j+m-1);
            else f[j] = mx[j-m]+getsum(j,j+m-1);
        }
        for(int j=1;j<=n;j++) mx[j]=max(mx[j-1],f[j]);
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}