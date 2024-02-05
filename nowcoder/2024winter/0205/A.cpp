#include <bits/stdc++.h>
using namespace std;
int t;
const int p0[]={100,29,30,31,32},
          p1[]={150,34,36,38,40},
          p2[]={200,45};
int check(int x) {
    for(auto i:p0) if(x==i) return 0;
    for(auto i:p1) if(x==i) return 1;
    for(auto i:p2) if(x==i) return 2;
}
int main() {
    cin>>t;
    while(t--) {
        int x,y,z; cin>>x>>y>>z;
        cout<<check(x)+check(y)+check(z)<<endl;
    }
}