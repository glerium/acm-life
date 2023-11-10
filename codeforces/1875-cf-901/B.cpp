#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=1e3+10;
int _,n,m,k;
ll a[maxn],b[maxn];
ll mia,mxa,mib,mxb;
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>n>>m>>k;
        rep(i,1,n) cin>>a[i];
        rep(i,1,m) cin>>b[i];
        rep(i,1,min(10,k)) {
            sort(a+1,a+1+n);
            sort(b+1,b+1+m);
            if(i&1) {
                if(b[m]>a[1])
                    swap(a[1],b[m]);
            }else{
                if(a[n]>b[1]) 
                    swap(a[n],b[1]);
            }
        }
        // cout<<";;;;"<<endl;
        // for(int i=1;i<=n;i++) cout<<a[i]<<' ';
        // cout<<endl;
        // for(int i=1;i<=m;i++) cout<<b[i]<<' ';
        // cout<<endl;
        if(k<=10) {
            ll ans=0;
            rep(i,1,n) ans+=a[i];
            cout<<ans<<endl;
        }else{
            sort(a+1,a+1+n);
            sort(b+1,b+1+m);
            if(k&1) swap(a[1],b[m]);
            ll ans=0;
            rep(i,1,n) ans+=a[i];
            cout<<ans<<endl;
        }
    }
    return 0;
}