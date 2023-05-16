#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    cin>>t;
    while(t--) {
        cin>>n;
        if(n==1) cout<<"1"<<endl;
        else if(n&1) cout<<"-1"<<endl;
        else {
            for(int i=n,j=1;i>=2&&j<=n-1;i-=2,j+=2)
                cout<<i<<' '<<j<<' ';
            cout<<endl;
        }
    }
    return 0;
}