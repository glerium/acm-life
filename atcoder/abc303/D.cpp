#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
const ll mx=1e16;
ll x,y,z,f[maxn][2];    // at i, j:capslock
char s[maxn];
int main() {
    // freopen("in.txt","r",stdin);
    cin>>x>>y>>z>>(s+1);
    int n=strlen(s+1);
    f[0][1]=mx;
    for(int i=1;i<=n;i++) {
        if(s[i]=='a') {
            f[i][0]=min(min(f[i-1][0]+x,f[i-1][0]+2*z+min(x,y)),min(f[i-1][1]+x+z,f[i-1][1]+y+z));
            f[i][1]=min(min(f[i-1][1]+y,f[i-1][1]+2*z+min(x,y)),min(f[i-1][0]+x+z,f[i-1][0]+y+z));
        }else{
            f[i][0]=min(min(f[i-1][0]+y,f[i-1][0]+2*z+min(x,y)),min(f[i-1][1]+x+z,f[i-1][1]+y+z));
            f[i][1]=min(min(f[i-1][1]+x,f[i-1][1]+2*z+min(x,y)),min(f[i-1][0]+x+z,f[i-1][0]+y+z));
        }
    }
    cout<<min(f[n][0],f[n][1])<<endl;
    return 0;
}