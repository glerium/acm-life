#include <bits/stdc++.h>
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=1e5+10;
int t,n,a[maxn],m,ddis1[maxn],dis1[maxn],ddis2[maxn],dis2[maxn];
signed main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        rep(i,0,n+1) dis1[i]=dis2[i]=ddis1[i]=ddis2[i]=0;
        ddis1[2]=1;
        rep(i,3,n) {
            if(a[i-1]-a[i-2]>a[i]-a[i-1]) {
                ddis1[i]=1;
            }else{
                ddis1[i]=a[i]-a[i-1];
            }
        }
        rep(i,2,n) dis1[i]=dis1[i-1]+ddis1[i];
        ddis2[n-1]=1;
        for(int i=n-2;i>=1;i--) {
            if(a[i+2]-a[i+1]>a[i+1]-a[i]) {
                ddis2[i]=1;
            }else{
                ddis2[i]=a[i+1]-a[i];
            }
        }
        for(int i=n;i>=1;i--) dis2[i]=dis2[i+1]+ddis2[i];
        cin>>m;
        while(m--) {
            int x,y; cin>>x>>y;
            if(x<y) cout<<dis1[y]-dis1[x]<<endl;
            else cout<<dis2[y]-dis2[x]<<endl;
        }
    }
    return 0;
}