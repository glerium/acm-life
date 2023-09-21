#include <bits/stdc++.h>
using namespace std;
int t;
vector<string> v = {"abc","acb","bac","cba"};
int main() {
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        bool ok=false;
        for(auto i:v) {
            if(i==s)
                ok=true;
        }
        puts(ok?"YES":"NO");
    }
    return 0;
}