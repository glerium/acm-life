#include <bits/stdc++.h>
using namespace std;
const int p=109;
int n,m;
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int ans=n;
    for(int i=2;i<=m;i++) ans=ans*(n-1)%p;
    cout<<ans<<endl;
    return 0;
}