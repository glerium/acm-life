#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int x,y,z;
        cin>>x>>y>>z;
        bool yes=(x*x+y*y+z*z==3*x*y*z);
        cout<<(yes?"Yes":"No")<<endl;
    }
}
