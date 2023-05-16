#include <bits/stdc++.h>
using namespace std;
int q,n,t,a[107],b[107];
int main(){
    cin>>q;
    while(q--){
        cin>>n>>t;
        int mx=-1,mxi=-1;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++) {
            if(i-1+a[i]<=t && b[i]>mx) {
                mx=b[i];
                mxi=i;
            }
        }
        cout<<mxi<<endl;
    }
    return 0;
}