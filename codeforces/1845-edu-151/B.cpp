#include <bits/stdc++.h>
using namespace std;
int t,x,y,a,b,c,d;
int main() {
    cin>>t;
    while(t--) {
        cin>>x>>y>>a>>b>>c>>d;
        int xx=x,yy=y;
        int ans=1;
        if(a>xx&&c>xx) {
            ans+=min(a,c)-xx;
            xx=min(a,c);
        }else if(a<xx&&c<xx) {
            ans+=xx-max(a,c);
            xx=max(a,b);
        }
        if(b>yy&&d>yy) {
            ans+=min(b,d)-yy;
            yy=min(b,d);
        }else if(b<yy&&d<yy) {
            ans+=yy-max(b,d);
            yy=max(b,d);
        }
        cout<<ans<<endl;
    }
    return 0;
}