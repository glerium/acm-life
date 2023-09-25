#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n,t;
    cin>>n;
    int ans=0;
    while(n--) {
        cin>>t;
        ans^=t;
    }
    cout<<ans<<endl;
    return 0;
}