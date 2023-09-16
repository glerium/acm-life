#include <bits/stdc++.h>
using namespace std;
int _;
string a,b;
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>a>>b;
        int n=a.size();
        int ok=false;
        for(int i=0;i<n-1;i++) {
            if(a[i]=='0'&&b[i]=='0'&&a[i+1]=='1'&&b[i+1]=='1') {
                ok=true;
                break;
            }
        }
        puts(ok?"YES":"NO");
    }
    return 0;
}