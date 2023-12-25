#include <bits/stdc++.h>
using namespace std;
int main() {
    const int maxn=107;
    int t,n,a[maxn];
    cin>>t;
    while(t--) {
        cin>>n;
        int ct=0,ctz=0;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            ct+=a[i]<0;
            ctz+=a[i]==0;
        }
        if(ctz) cout<<0<<endl;
        else{
            if(ct&1) cout<<0<<endl;
            else {
                cout<<1<<endl;
                cout<<"1 0"<<endl;
            }
        }
    }
}