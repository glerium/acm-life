#include <bits/stdc++.h>
using namespace std;
int main() {
    int c,d,n,m,k;
    cin>>c>>d>>n>>m>>k;
    int ans=INT_MAX;
    for(int i=0;i<=10000;i++) {
        for(int j=0;j<=10000;j++) {
            if(n*i+1*j+k>=n*m){
                ans=min(ans,i*c+j*d);
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}