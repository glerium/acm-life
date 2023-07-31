#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int t,n;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>s;
        bool same=s[0]==s[s.size()-1];
        bool ok=true;
        char ch = s[0]=='0'?'1':'0';
        if(same) {
            char cc = s[1];
            for(int i=1;i<s.size()-1;i++) if(s[i]!=cc) {
                ok=false;
                break;
            }
        }
        putchar(!same||ok?ch=='0'?'1':'0':ch);
        for(int i=2;i<=n;i++) putchar(ch);
        putchar('\n');
    }
    return 0;
}