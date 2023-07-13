#include <bits/stdc++.h>
using namespace std;
int t,a,b;
int main() {
    cin>>t;
    while(t--) {
        cin>>a>>b;
        if(a>b) swap(a,b);
        if(a>1) {
            cout<<1<<endl;
        }else{
            if(b==2) cout<<3<<endl;
            else cout<<2<<endl;
        }
    }
}