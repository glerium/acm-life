#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int a[107];
int main(){
    for(int i=2;i<=100;i++) a[i] = i*(i-1)/2;
    cin>>t;
    while(t--){
        cin>>n>>k;
        bool yes=false;
        // printf("ans:");
        for(int i=0;i<=n;i++) {
            if(a[i]+a[n-i]==k) {
                printf("YES\n");
                for(int j=1;j<=i;j++) printf("%d ",1);
                for(int j=i+1;j<=n;j++) printf("%d ",-1);
                cout<<endl;
                yes=true;
                break;
            }
        }
        if(!yes) cout<<"NO"<<endl;
    }
    return 0;
}