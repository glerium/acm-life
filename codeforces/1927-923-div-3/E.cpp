#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n+10);
    int x=1,y=n;
    for(int i=1;i<=k;i++) {
        for(int j=i;j<=n;j+=k) {
            if(j%2==0) a[j]=x++;
            else a[j]=y--;
        }
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<endl;
}
int main() {
    int t; cin>>t;
    while(t--) solve();
    return 0;
}