#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>s;
        for(char i='a';i<='h';i++) {
            if(s[0]!=i)
                cout<<i<<s[1]<<endl;
        }
        for(char i='1';i<='8';i++) {
            if(s[1]!=i)
                cout<<s[0]<<i<<endl;
        }
    }
}