#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=100;
int n,t;
int main() {
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++) {
        cin>>t;
        ans^=t;
    }
    if(ans) cout<<0<<endl;
    else cout<<(1ll<<n)<<endl;
}