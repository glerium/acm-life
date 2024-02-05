#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=1e5+10;
int t,n,m;
struct Data{
    int x,y;
    bool operator<(const Data& rhs)const{
        return x<rhs.x;
    }
}a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>m;
        rep(i,1,n) cin>>a[i].x>>a[i].y;
        sort(a+1,a+1+n);
        long long dis=0,ans=m;
        for(int i=1;i<=n;i++) {
            dis+=a[i].y;
            if(a[i].x-dis<=m) ans=max(ans,m+dis);
        }
        cout<<ans<<endl;
    }
    return 0;
}