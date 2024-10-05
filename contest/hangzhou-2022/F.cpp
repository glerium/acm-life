#include <bits/stdc++.h>
// #define cout cout<<"out: "
using namespace std;
const int maxn=1e4+10;
set<string> st;
int t,n,m[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    string s;
    for(int i=1;i<=n;i++) {
        int m; cin>>m;
        vector<string> ans;
        for(int j=1;j<=m;j++) {
            cin>>s;
            if(s.find("bie")!=string::npos&&!st.count(s)) {
                ans.push_back(s);
                st.insert(s);
            }
        }
        if(ans.size()==0) cout<<"Time to play Genshin Impact, Teacher Rice!"<<endl;
        else {
            for(auto i : ans) cout<<i<<endl;
        }
    }
}