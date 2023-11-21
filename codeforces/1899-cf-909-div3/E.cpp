#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=2e5+10;
int t,n,a[maxn],b[maxn],rk[maxn];
map<int,int> st;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        rep(i,1,n) b[i]=a[i];
        sort(b+1,b+1+n);
        int mi=1e9+1;
        rep(i,1,n) mi=min(mi,a[i]);
        int ans=-1;
        rep(i,1,n) {
            if(a[i]==mi) {
                ans=i;
                int j;
                for(j=i;j<=n;j++) {
                    int o=j-i+1;
                    if(a[j]!=b[o]) {
                        break;
                    }
                }
                j--;
                for(;j<n;j++) {
                    if(a[j]>a[j+1]) {
                        cout<<-1<<endl;
                        goto end;
                    }
                }
                break;
            }
        }
        cout<<ans-1<<endl;
end:    ;
    }
}