#include <bits/stdc++.h>
using namespace std;
int main() {
    long long x,y,ans=0;
    cin>>x>>y;
    while(x!=0&&y!=0) {
        if(x>y) swap(x,y);
        ans+=y/x*x*4;
        y%=x;
    }
    cout<<ans<<endl;
    return 0;
}