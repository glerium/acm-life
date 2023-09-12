#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n;
ll x[maxn],y[maxn],z[maxn];
ll ax,ay,az,bx,by,bz;
ll getans(ll *arr, int pos) {
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=abs(arr[i]-arr[pos]);
    return ans;
}
ll get2(ll *arr, int pos) {
    ll ans=0;
    for(int i=1;i<=n;i++) {
        int target = arr[pos]-(pos-i);
        ans += abs(target-arr[i]);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>z[i];
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    sort(z+1,z+1+n);
    int mid=(n+1)/2;
    ax = getans(x,mid);
    ay = getans(y,mid);
    az = getans(z,mid);
    bx=by=bz=LLONG_MAX;
    for(int i=max(1,mid-1);i<=min(n,mid+1);i++) 
        bx = min(bx,get2(x,i));
    for(int i=max(1,mid-1);i<=min(n,mid+1);i++) 
        by = min(by,get2(y,i));
    for(int i=max(1,mid-1);i<=min(n,mid+1);i++) 
        bz = min(bz,get2(z,i));
    ll ans = min(ax+ay+bz,min(ax+az+by,ay+az+bx));
    cout<<ans<<endl;
}