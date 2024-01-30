#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string a,b,c; cin>>a>>b>>c;
        bool ok=false;
        for(int i=0;i<n;i++) {
            if(c[i]!=a[i]&&c[i]!=b[i]) {
                ok=true;
                break;
            }
        }
        puts(ok?"YES":"NO");
    }
    return 0;
}