#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin>>n;
    vector<int> a(n+5), b(n+5);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    if(n==1) {
        cout<<-1<<endl;
        return;
    }
    if(n==2) {
        if(a[1]==b[1]) {
            cout<<-1<<endl;
            return;
        }else {
            cout<<1<<endl;
            return;
        }
    }
    for(int i=1;i<n;i++) {
        if(a[i]==b[i+1]||b[i]==a[i+1]){
            cout<<1<<endl;
            return;
        }
    }
    for(int i=2;i<n;i++) {
        if(a[i]==b[i]){
            cout<<1<<endl;
            return;
        }
    }
    cout<<2<<endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) solve();
}