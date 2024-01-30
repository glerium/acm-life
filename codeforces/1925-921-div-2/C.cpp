#include <bits/stdc++.h>
using namespace std;
int t,n,k,m;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>k>>m>>s;
        int ct=0;
        set<char> st;
        string ans;
        for(int i=0;i<m;i++) {
            st.insert(s[i]);
            if(st.size()==k) {
                ct++;
                ans.push_back(s[i]);
                st.clear();
            }
        }
        if(ct>=n) cout<<"YES"<<endl;
        else {
            cout<<"NO"<<endl;
            cout<<ans;
            for(char ch='a';ch<='z';ch++) {
                if(!st.count(ch)) {
                    for(int i=ct+1;i<=n;i++)
                        cout<<ch;
                    break;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}