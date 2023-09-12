#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,mi[maxn];
struct Cat{
    int p,v;
    bool operator<(const Cat& rhs) const{
        return p==rhs.p ? v>rhs.v : p<rhs.p;
    }
}a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].p>>a[i].v;
    sort(a+1,a+1+n);
    int vm = 0x3f3f3f3f;
    mi[n+1]=0x3f3f3f3f;
    int ans=0,now=0;
    for(int i=n;i>=1;i--) {
        if(a[i].v>mi[i+1]) now++,ans=max(ans,now);
        else now=1;
        mi[i]=min(mi[i+1],a[i].v);
    }
    ans=max(ans,now);
    cout<<ans<<endl;
}