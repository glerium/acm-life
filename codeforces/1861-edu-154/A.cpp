#include <bits/stdc++.h>
using namespace std;
int _;
string n;
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>n;
        int p3,p7;
        for(int i=0;i<n.size();i++) {
            if(n[i]=='3') p3=i;
            else if(n[i]=='7') p7=i;
        }
        if(p3<p7) cout<<37<<endl;
        else cout<<73<<endl;
    }
    return 0;
}