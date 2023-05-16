#include <bits/stdc++.h>
using namespace std;
int t,n,m;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        int k=n*m;
        long long mx=-1e6,mx2=-1e6,mi=1e6,mi2=1e6;
        while(k--){
            int t; cin>>t;
            if(t>=mx) {
                mx2=mx;
                mx=t;
            }else if(t>mx2)
                mx2=t;
            if(t<=mi) {
                mi2=mi;
                mi=t;
            } else if(t<mi2)
                mi2=t;
        }
        long long ans=0;
        ans=max(ans,mx*n*m-mi*n*(m-1)-mi2*(n-1)-mx);
        ans=max(ans,mx*n*m-mi2*(m-1)-mi*(n-1)*m-mx);
        ans=max(ans,-mi*n*m+mx*n*(m-1)+mx2*(n-1)+mi);
        ans=max(ans,-mi*n*m+mx*(n-1)*m+mx2*(m-1)+mi);
        cout<<ans<<endl;
    }
    return 0;
}