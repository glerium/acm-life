#include <bits/stdc++.h>
using namespace std;
int n,x,tmp;
int main() {
    cin>>n>>x;
    int ans=0;
    while(n--) {
        cin>>tmp;
        ans+=tmp<=x?tmp:0;
    }
    cout<<ans<<endl;
    return 0;
}