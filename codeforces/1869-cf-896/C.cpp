#include <bits/stdc++.h>
using namespace std;
int t,n,m;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>m;
        if(m==1){
            for(int i=1;i<=n+1;i++) cout<<0<<endl;
        }else{
            cout<<min(n+1,m)<<endl;
            if(m>=n+1){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++)
                        cout<<(i+j-2+m*5)%m<<' ';
                    cout<<endl;
                }
            }else{
                for(int i=1;i<=m-1;i++){
                    for(int j=1;j<=m;j++)
                        cout<<(i+j-2+m*5)%m<<' ';
                    cout<<endl;
                }
                for(int i=m;i<=n;i++){
                    for(int j=1;j<=m;j++)
                        cout<<j-1<<' ';
                    cout<<endl;
                }
            }
        }
    }
}