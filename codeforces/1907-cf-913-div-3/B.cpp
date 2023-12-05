#include <bits/stdc++.h>
using namespace std;
int t;
string s;
vector<int> u,d;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>s;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='B') {
                if(!u.empty())
                    u.pop_back();
            }else if(s[i]=='b') {
                if(!d.empty())
                    d.pop_back();
            }else if(isupper(s[i])) {
                u.push_back(i);
            }else{
                d.push_back(i);
            }
        }
        for(auto i:d) u.push_back(i);
        sort(u.begin(), u.end());
        for(auto i:u) putchar(s[i]);
        putchar('\n');
        u.clear();
        d.clear();
    }
}