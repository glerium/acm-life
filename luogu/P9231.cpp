#include <bits/stdc++.h>
using namespace std;
int main() {
    int l,r;
    cin>>l>>r;
    int ans=0;
    for(int i=l;i<=r;) {
        if(i%4==2) {
            ans+=1;
            i+=4;
        } else i++;
    }
    cout<<r-l+1-ans<<endl;
    return 0;
}