#include <bits/stdc++.h>
using namespace std;
int t,n;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        if(n%6==0) cout<<n/6<<endl;
        else cout<<(n/6)*2<<endl;
    }
}