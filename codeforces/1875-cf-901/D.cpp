#include <bits/stdc++.h>
#define int long long 
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
constexpr int maxn=5e3+10;
int _,n,a[maxn],p[maxn],f[maxn];
signed main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>n;
        rep(i,0,n+10) f[i]=p[i]=0;
        rep(i,1,n) {
            cin>>a[i];
            if(a[i]<=n)
                p[a[i]]++;
        }
        int mex=-1,ct=0;
        rep(i,0,n+1) {
            ct+=p[i];
            if(p[i]==0) {
                mex=i;
                break;
            }
        }
        n=ct;
        per(i,mex-1,0) {
            f[i]=0x3f3f3f3f3f3f3f3f;
            rep(j,i+1,mex) {
                f[i]=min(f[i],f[j]+i+j*(p[i]-1));
            }
        }
        cout<<f[0]<<endl;
    }
    return 0;
}