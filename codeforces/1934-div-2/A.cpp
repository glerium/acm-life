#include <iostream>
#include <algorithm>
using namespace std;
void solve() {
    int n; cin>>n;
    int a[n+5];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1, a+1+n);
    cout<<(a[n]+a[n-1]-a[1]-a[2])*2<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) solve();
}