#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=2e5+10;
int t,n,q[maxn];
long long a[maxn],b[maxn];
bool cmp(int x,int y) {
    return a[x]+b[x]>a[y]+b[y];
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        rep(i,1,n) cin>>b[i];
        rep(i,1,n) q[i]=i;
        sort(q+1,q+1+n,cmp);
        bool alice=true;
        long long ans=0;
        rep(i,1,n) {
            if(alice) ans+=a[q[i]]-1;
            else ans-=b[q[i]]-1;
            alice=!alice;
        }
        cout<<ans<<endl;
    }
}