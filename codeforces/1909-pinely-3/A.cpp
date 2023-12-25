#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int t,n;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        bool x_0=true, x_1=true, y_0=true, y_1=true;
        while(n--) {
            int x,y; cin>>x>>y;
            if(x<0) x_1=false;
            else if(x>0) x_0=false;
            if(y<0) y_1=false;
            else if(y>0) y_0=false;
        }
        if(x_0||x_1||y_0||y_1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}