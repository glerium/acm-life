#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
ll t,n,k,a,b,c[maxn][10];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>k>>a>>b;
        for(int i=1;i<=n;i++) for(int j=1;j<=2;j++) cin>>c[i][j];
        ll ans = abs(c[a][1]-c[b][1]) + abs(c[a][2]-c[b][2]);
        ll nw = 0;
        ll ttt = LLONG_MAX;
        for(int i=1;i<=k;i++) 
            ttt = min(ttt, (ll)(abs(c[a][1]-c[i][1]) + abs(c[a][2]-c[i][2])));
        ll sss = LLONG_MAX;
        for(int i=1;i<=k;i++) 
            sss = min(sss, (ll)(abs(c[b][1]-c[i][1]) + abs(c[b][2]-c[i][2])));
        if(ttt!=LLONG_MAX&&sss!=LLONG_MAX){
            nw = ttt + sss;
            ans = min(ans, nw);
        }
        cout<<ans<<endl;
    }
}