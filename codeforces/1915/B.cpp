#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        string s;
        for(int i=1;i<=3;i++) {
            cin>>s;
            bool a=0,b=0,c=0;
            for(auto j:s) {
                a|=j=='A';
                b|=j=='B';
                c|=j=='C';
            }
            if(!a) cout<<'A'<<endl;
            else if(!b) cout<<"B"<<endl;
            else if(!c) cout<<"C"<<endl;
        }
    }
    return 0;
}