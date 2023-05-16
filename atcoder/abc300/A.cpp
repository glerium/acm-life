#include <bits/stdc++.h>
using namespace std;
int n,x,y,t;
int main(){
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++) {
        cin>>t;
        if(x+y==t) {
            cout<<i<<endl;
            break;
        }
    }
}