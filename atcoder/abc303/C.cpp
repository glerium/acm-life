#include <bits/stdc++.h>
using namespace std;
int n,m,h,k;
string s;
set<pair<int,int>> st;
int main() {
    cin>>n>>m>>h>>k>>s;
    for(int i=1;i<=m;i++) {
        int x,y; cin>>x>>y;
        st.insert(make_pair(x,y));
    }
    bool yes=true;
    int x=0,y=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='R') x++;
        else if(s[i]=='L') x--;
        else if(s[i]=='U') y++;
        else y--;
        h--;
        if(h<0) {
            yes=false;
            break;
        }
        if(st.count(make_pair(x,y))) {
            if(h<k) {
                h=k;
                st.erase(make_pair(x,y));
            }
        }
    }
    puts(yes?"Yes":"No");
    return 0;
}